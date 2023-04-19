#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <arduino-timer.h> // https://github.com/contrem/arduino-timer // Copyright (c) 2018, Michael Contreras

// ======================================
// Created by:  Thresa Kelly
// Email:       ThresaKelly133@gmail.com
// ======================================

////////////////////////////////////////////////////////////////////////////////////
// vvv Display screen stuff vvv
////////////////////////////////////////////////////////////////////////////////////
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

////////////////////////////////////////////////////////////////////////////////////
// vvv arduino-timer stuff vvv
////////////////////////////////////////////////////////////////////////////////////

// timer 
auto timer = timer_create_default(); // create a timer with default settings

////////////////////////////////////////////////////////////////////////////////////
// vvv my globals vvv
////////////////////////////////////////////////////////////////////////////////////

//// structs ////

// data packet read from software 
struct packet {
  int commandNumber;
  int objectID;
  int data;
};

//  holds character array of hex numbers with array size
struct hexString {
  char * hex;
  int    size;
};

//// constants ////

// command IDs
const int PING       = 0;
const int TESTLED    = 1; // not implemented in software
const int BATTERY    = 2; // not implemented in software
const int CALIBRATE  = 3; // not implemented in software
const int NTRIALS    = 4;
const int TRIAL      = 5;
const int SEPARATION = 6;
const int TIMEOUT    = 7;
const int SAMPLERATE = 8;
const int STREAM     = 9;

// number of objects
const int NOBJECTS   = 12;

// constant for bad no value or bad value
const int NOVALUE    = -1;

// system states 
const int MODE_INIT   = 0; // setting experiment parameters 
const int MODE_STREAM = 1; // experiment running

//// variables ////

// experiment state
int   _state           = NOVALUE;

// experiment parameters
int   _numberOfTrials  = NOVALUE;
int * _trialSequence   = nullptr;
int   _separation_ms   = NOVALUE;
int   _timeout_ms      = NOVALUE; 
int   _sampleRate_Hz   = NOVALUE;

// current experiment status
int   _currentTrial    = NOVALUE; // trial number (1 to _numberOfTrials)
int   _currentObject   = NOVALUE; // ID of object that was moved

////////////////////////////////////////////////////////////////////////////////////
// vvv Arduino functions vvv
////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // setup display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(500);

  TestDisplay();
  delay(500);
}

// put your main code here, to run repeatedly:
void loop() {

  // read one data packet from computer and do the command 
  if(Serial.available() > 0){
    bool status = DoCommand(ReadCommand());  
  }

  // experiment running    
  if(_state == MODE_STREAM){
    timer.tick();
  }
  
  // delay(1000);
  // ClearScreen();
  // delay(200);
}

////////////////////////////////////////////////////////////////////////////////////
// vvv timer vvv
////////////////////////////////////////////////////////////////////////////////////

bool TimerEvent_WriteSTREAM(void *)
{
  bool keepTimerActive = true;

  // check for valid parameters
  if(_currentTrial < 1 || _state != MODE_STREAM ){
    keepTimerActive = false;
    DisplayInt(_state); // testing
  }
  else{
    // write data to computer 
    WritePacket(STREAM, _currentObject, _currentTrial); 

    // testing 
    DisplayInt(_currentTrial);
    _currentTrial += 1;
  }

  return keepTimerActive;
}

////////////////////////////////////////////////////////////////////////////////////
// vvv screen control vvv
////////////////////////////////////////////////////////////////////////////////////

void ClearScreen()
{
  display.clearDisplay();
  display.setCursor(0,20);
  display.display();    
}

void TestDisplay()
{
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println("Hello, world!");
  display.display();
}

void DisplayPacket(int commandNumber, int objectID, int data)
{
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(commandNumber);
  display.println(objectID);
  display.println(data);
  display.display();
}

void DisplayPacket(char * commandNumber, char * objectID, char * data)
{
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(commandNumber);
  display.println(objectID);
  display.println(data);
  display.display();
}

void DisplayChar(char * pkt)
{
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(pkt);
  display.display();
}

void DisplayInt(int n)
{
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(n);
  display.display();  
}

////////////////////////////////////////////////////////////////////////////////////
// vvv data packets vvv
////////////////////////////////////////////////////////////////////////////////////

bool WritePacket(struct packet p)
{
  return(WritePacket(p.commandNumber, p.objectID, p.data));
}

bool WritePacket(int commandNumber, int objectID, int data)
{  
  // check packet inputs 
  if( ( commandNumber > STREAM   ) || // check that command number is valid 
      ( commandNumber < PING     ) ||
      ( objectID      > NOBJECTS ) || // check for valid ID 
      ( objectID      < 0        )
  ){
    return(false);
  }

  // convert to hex
  struct hexString cmdHex  = IntToHexString(commandNumber);
  struct hexString idHex   = IntToHexString(objectID);
  struct hexString dataHex = IntToHexString(data);

  // check char* sizes
  if( (cmdHex.size  > 1) ||
      (idHex.size   > 1) ||
      (dataHex.size > 4)
  ){
    // delete pointers to prevent memory leak
    delete[] cmdHex.hex;
    delete[] idHex.hex;
    delete[] dataHex.hex;
    return(false);
  }  
  
  // initialize packet of 8 bytes
  char command[] = "00000000";

  // set start/stop flags
  command[0] = 0x02; // STX
  command[7] = 0x03; // ETX
  
  // write command info 
  command[1] = cmdHex.hex[0];
  command[2] = idHex.hex[0];
  if(dataHex.size == 4){
    command[3] = dataHex.hex[0];
    command[4] = dataHex.hex[1];
    command[5] = dataHex.hex[2];
    command[6] = dataHex.hex[3];
  } else if(dataHex.size == 3){
    command[4] = dataHex.hex[0];
    command[5] = dataHex.hex[1];
    command[6] = dataHex.hex[2];    
  }else if(dataHex.size == 2){
    command[5] = dataHex.hex[0];
    command[6] = dataHex.hex[1];       
  } else { // data.size == 1
    command[6] = dataHex.hex[0];     
  }

  // write to computer 
  Serial.write(command);

  // delete pointers to prevent memory leak
  delete[] cmdHex.hex;
  delete[] idHex.hex;
  delete[] dataHex.hex;
  
  // return true for successful write
  return(true);
}


struct packet ReadCommand(){
  // init strings
  char b0_stx[]     = "0"; // note: string terminates with '\0'
  char b1_cmd[]     = "0";
  char b2_id[]      = "0";
  char b3456_data[] = "0000";
  char b7_etx[]     = "0";

  // read until STX found, which marks the start of a data packet
  while(true){
    // wait for data 
    if(Serial.available() > 0){
      // read a byte
      b0_stx[0] = Serial.read();
      // check if byte is STX
      if(b0_stx[0] == 0x02){
        break;
      }
    }        
  }   
  
  // wait for full packet to be available 
  while(Serial.available() < 7){
    delayMicroseconds(200); // 0.2 ms
  }

  // read next bytes  
  b1_cmd[0]   = Serial.read();
  b2_id[0]    = Serial.read();
  b3456_data[0] = Serial.read();
  b3456_data[1] = Serial.read();
  b3456_data[2] = Serial.read();
  b3456_data[3] = Serial.read();
  b7_etx[0]   = Serial.read();

  // verify that last byte is ETX, which ends the packet
  if( b7_etx[0] != 0x03){
    // bad packet, try to read again 
    return(ReadCommand());
  }

  // convert hex characters into integers and add to struct 
  struct packet p;
  p.commandNumber = HexStringToInt(b1_cmd);
  p.objectID      = HexStringToInt(b2_id);
  p.data          = HexStringToInt(b3456_data);

  // return packet 
  return(p);
}

int HexStringToInt(char str[])
{
  // convert unsigned hex string into integer
  return (int) strtoul(str, 0, 16);
}

struct hexString IntToHexString(uint n){
  // init struct 
  struct hexString hs; 
  
  // check edge case
  if(n == 0){
    // only 1 digit needed for 0 hex
    hs.size = 1;    
  }
  else{
    // calculate number of digits needed to represent number in hex
    hs.size = floor( log(n)/log(16) ) + 1;       
  }

  // convert n to hex string 
  hs.hex = new char[hs.size];
  sprintf(hs.hex, "%X", n);
  
  // return hex string of n   
  return(hs);
}

////////////////////////////////////////////////////////////////////////////////////
// vvv run commands vvv
////////////////////////////////////////////////////////////////////////////////////

bool DoCommand(struct packet currentCommand)
{
  // true when command was successful, false if failed
  bool status = false;  

  // easy access of struct parts
  int cmd  = currentCommand.commandNumber;
  int id   = currentCommand.objectID;
  int data = currentCommand.data;

  // choose function using command number 
  switch(cmd) {
    case PING:
      status = Ping();  
      break;
    case TESTLED:
      status = TestLED(id,data);  // not implemented in software
      break;
    case BATTERY:
      status = Battery(id);       // not implemented in software
      break;
    case CALIBRATE:
      status = Calibrate(id);     // not implemented in software
      break;
    case NTRIALS:
      status = NTrials(data);
      break;
    case TRIAL:
      status = Trial(id,data);
      break;      
    case SEPARATION:
      status = Separation(data);
      break;
    case TIMEOUT:
      status = Timeout(data);
      break;
    case SAMPLERATE:
      status = SampleRate(data);
      break;
    case STREAM:
      status = Stream(data);
      break;
    default:
      status = NoCommand();
  }

  return(status);  
}

bool Ping()
{
  // true for successful command implementation, false otherwise
  bool status = WritePacket(PING,0,0);
  return(status);
}

bool TestLED(int id, int time_ms)
{
  // not implemented
  return(false); // temp
}

bool Battery(int id)
{
  // not implemented
  return(false); // temp
}

bool Calibrate(int id)
{
  // not implemented 
  return(false); // temp
}

bool NTrials(int numberOfTrials)
{
  // true for successful command implementation, false otherwise
  bool status = false;

  if(numberOfTrials > 0){
    // set number of trials globally
    _numberOfTrials = numberOfTrials;
    
    // clear out old array
    if(_trialSequence != nullptr){
      delete[] _trialSequence;
      _trialSequence = nullptr;
    }  
    
    // initalize sequence array of size _trialSequence and fill with -1s
    _trialSequence = new int[numberOfTrials]; 
    for(int i=0; i<numberOfTrials; i++){
      _trialSequence[i] = NOVALUE;
    } 

    // write back command
    status = WritePacket(NTRIALS,0,_numberOfTrials);   
  }
  // else { bad input, do not write back to software }
  return(status);
}

bool Trial(int id, int trialNumber)
{
  // true for successful command implementation, false otherwise
  bool status = false;
  
  if(_trialSequence != nullptr){
    // set trial 
    _trialSequence[trialNumber-1] = id;

    // write back command
    status = WritePacket(TRIAL,_trialSequence[trialNumber-1],trialNumber);    
  }
  // else { need NTrials first, do not write back to software }
  return(status);
}

bool Separation(int time_ms)
{
  // true for successful command implementation, false otherwise
  bool status = false;

  if(time_ms > 0){
    // set time 
    _separation_ms = time_ms;
    // write back command
    bool status = WritePacket(SEPARATION,0,_separation_ms);
  }
  // else { bad input, do not write back to software }
  return(status);
}

bool Timeout(int time_ms)
{
  // true for successful command implementation, false otherwise
  bool status = false;
  
  if(time_ms > 0){
    // set time
    _timeout_ms = time_ms;
    // write back command
    bool status = WritePacket(TIMEOUT,0,_timeout_ms);    
  }
  // else { bad input, do not write back to software }
  return(status);
}

bool SampleRate(int frequency_Hz)
{
  // true for successful command implementation, false otherwise
  bool status = false;
  
  if(frequency_Hz > 0){
    // set frequency 
    _sampleRate_Hz = frequency_Hz;
    // write back command
    bool status = WritePacket(SAMPLERATE,0,_sampleRate_Hz); 
  }
  // else { bad input, do not write back to software }
  return(status);
}

bool Stream(int flag)
{
  // true for successful command implementation, false otherwise
  bool status = false;
  
  if(flag == 0){
    // stop experiment
    _state = MODE_INIT;  
    // reset experiment variables
    _currentTrial  = NOVALUE;
    _currentObject = NOVALUE;
  }
  else if(flag == 1){
    // start experiment 
    _state = MODE_STREAM;
    // reset experiment variables
    _currentTrial  = 1;
    _currentObject = 0;
    // start timer 
    int dt_ms = (1.0 / _sampleRate_Hz) * 1000; // (1/[Hz]) = [s] // [s] * 1000[ms]/[s] = [ms]
    timer.every(dt_ms, TimerEvent_WriteSTREAM);
  }
  else{
    return(status);    
  }
  
  status = WritePacket(STREAM,0,_state); 
  return(status); 
}

bool NoCommand()
{
  return(false);
}