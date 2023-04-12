#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// vvv Display screen stuff
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// ^^^ Display screen stuff

// command IDs
const int PING       = 0;
const int TESTLED    = 1;
const int BATTERY    = 2;
const int CALIBRATE  = 3;
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

  // read one data packet from computer 
  // struct packet p = readCommand();
  // DoCommand(p);

  // show to screen
  // DisplayPacket(p);

  // struct packet p;
  // p.commandNumber = 4;
  // p.objectID = 0;
  // p.data = 10;

  char * hex1 = IntToHexString(10);
  char * hex2 = IntToHexString(1000);
  // bool writeStatus = WritePacket(p)

  display.clearDisplay();
  display.setCursor(0,20);  
  display.println(10);             
  display.println(hex1);
  display.println(1000);             
  display.println(hex2);
  // display.println(hex[2]);
  // display.println(hex[3]);
  // display.println(hex[4]);
  // display.println(hex[5]);
  display.display();
  
  delay(1000);
  ClearScreen();
  delay(200);

  delete[] hex1;
  delete[] hex2;
}

bool WritePacket(struct packet p)
{  
  // convert to hex
  char * cmd  = IntToHexString(p.commandNumber);
  char * id   = IntToHexString(p.objectID);
  char * data = IntToHexString(p.data);

  // check size 
  int cmdsize = sizeof(cmd) / sizeof(int) ;

  // initialize packet of 8 bytes
  char command[] = "00000000";
  
  // TODO write packet

  // convert int to hex string
  // concatenate STX+cmd+id+data+ETX
  // write packet to computer

  // return true for successful write, false for error or bad inputs  
  return(false);
}

char * IntToHexString(int n){
  // calculate number of digits needed to represent number in hex 
  int size = floor( log(n)/log(16) ) + 1;
  // get hex string 
  char * hex = new char[size];
  sprintf(hex, "%X", n);
  return(hex);
}

void ClearScreen()
{
  display.clearDisplay();
  display.setCursor(0,20);
  display.display();    
}

void DisplayPacket(struct packet p)
{
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(p.commandNumber);
  display.println(p.objectID);
  display.println(p.data);
  display.display();
}

struct packet readCommand(){
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
    return(readCommand());
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
  
}

void TestLED(int id, int time_ms)
{
  
}

void Battery(int id)
{
  
}

void Calibrate(int id)
{

}

void NTrials(int numberOfTrials)
{
  
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