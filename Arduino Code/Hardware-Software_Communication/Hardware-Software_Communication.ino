#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*
*   @author: Thresa Kelly
*/

// vvv Display screen stuff
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// ^^^ Display screen stuff

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

// global variables
int   _numberOfTrials  = -1;
int * _trialSequence = nullptr;
int   _separation_ms   = -1;
int   _timeout_ms      = -1; 
int   _sampleRate_Hz   = -1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // setup display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

  // test display
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println("Hello, world!");
  display.display();
  delay(2000); 
}

// put your main code here, to run repeatedly:
void loop() {

  /////////////////////////////////////////////
  // read one data packet from computer 
  DoCommand(ReadCommand());
  /////////////////////////////////////////////

  // show to screen
  // DisplayPacket(p);

  // struct hexString hs = IntToHexString(100);
  // display.clearDisplay();
  // display.setCursor(0,20);             
  // display.println(hs.hex);
  // display.println(hs.size);
  // display.display();
  // delete[] hs.hex;

  // struct packet p;
  // p.commandNumber = 4;
  // p.objectID = 0;
  // p.data = 10;

  // bool writeStatus = WritePacket(p);
  // // Ping();
  
  delay(1000);
  // ClearScreen();
  // delay(200);
}

void ClearScreen()
{
  display.clearDisplay();
  display.setCursor(0,20);
  display.display();    
}

bool WritePacket(struct packet p)
{
  return(WritePacket(p.commandNumber, p.objectID, p.data));
}

bool WritePacket(int commandNumber, int objectID, int data)
{  
  // check packet inputs 
  if( (commandNumber > STREAM) || // check that command number is valid 
      (commandNumber < PING) ||
      (objectID > NOBJECTS) ||    // check for valid ID 
      (objectID < 0)
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

  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(command);
  display.display();

  // delete pointers to prevent memory leak
  delete[] cmdHex.hex;
  delete[] idHex.hex;
  delete[] dataHex.hex;
  
  // return true for successful write
  return(true);
}

struct hexString IntToHexString(uint n){
  struct hexString hs; 
  if(n == 0){
    hs.size = 1;    
  }
  else{
    // calculate number of digits needed to represent number in hex
    hs.size = floor( log(n)/log(16) ) + 1;       
  }
  // convert n to hex string 
  hs.hex = new char[hs.size];
  sprintf(hs.hex, "%X", n);   
  return(hs);
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
    delay(0.5);
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

  return(p);
}

int HexStringToInt(char str[])
{
  // convert unsigned hex string into integer
  return (int) strtoul(str, 0, 16);
}


void DoCommand(struct packet currentCommand)
{
  // easy access of struct parts
  int cmd  = currentCommand.commandNumber;
  int id   = currentCommand.objectID;
  int data = currentCommand.data;

  // choose function using command number 
  switch(cmd) {
    case PING:
      Ping();  
      break;
    case TESTLED:
      TestLED(id,data);
      break;
    case BATTERY:
      Battery(id);
      break;
    case CALIBRATE:
      Calibrate(id);
      break;
    case NTRIALS:
      NTrials(data);
      break;
    case TRIAL:
      Trial(id,data);
      break;      
    case SEPARATION:
      Separation(data);
      break;
    case TIMEOUT:
      Timeout(data);
      break;
    case SAMPLERATE:
      SampleRate(data);
      break;
    case STREAM:
      Stream(data);
      break;
    default:
      NoCommand();
  }
}

void Ping()
{
  bool status = WritePacket(PING,0,0);
}

void TestLED(int id, int time_ms)
{
  // not implemented 
}

void Battery(int id)
{
  // not implemented 
}

void Calibrate(int id)
{
  // not implemented 
}

void NTrials(int numberOfTrials)
{
  // set number of trials globally
  _numberOfTrials = numberOfTrials;
  
  // clear out old array
  if(_trialSequence != nullptr){
    delete[] _trialSequence;
    _trialSequence = nullptr;
  }  
  
  if(numberOfTrials > 0){
    // initalize sequence array of size _trialSequence and fill with -1s
    _trialSequence = new int[numberOfTrials]; 
    for(int i=0; i<numberOfTrials; i++){
      _trialSequence[i] = -1;
    } 

    // write back command
    bool status = WritePacket(NTRIALS,0,_numberOfTrials);   
  }
  // else { bad input, do not write back to software }
}

void Trial(int id, int trialNumber)
{
  
}

void Separation(int time_ms)
{
  
}

void Timeout(int time_ms)
{

}

void SampleRate(int frequency_Hz)
{
  
}

void Stream(int flag)
{
  
}

void NoCommand()
{
  
}