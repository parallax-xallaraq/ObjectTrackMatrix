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
  struct packet p = readCommand();

  // show to screen for 1 sec
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(p.commandNumber);
  display.println(p.objectID);
  display.println(p.data);
  display.display();
  delay(1000);
  
  // clear screen
  display.clearDisplay();
  display.setCursor(0,20);
  display.display();
  delay(1000);
  
}

struct packet readCommand(){
  // init strings
  char b0_stx[]   = "0"; // note: string terminates with '\0'
  char b1_cmd[]   = "0";
  char b2_id[]    = "0";
  char b34_data[] = "00";
  char b6_etx[]   = "0";

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
  while(Serial.available() < 5){
    delay(0.5);
  }

  // read next 5 bytes  
  b1_cmd[0]   = Serial.read();
  b2_id[0]    = Serial.read();
  b34_data[0] = Serial.read();
  b34_data[1] = Serial.read();
  b6_etx[0]   = Serial.read();

  // verify that last byte is ETX, which ends the packet
  if( b6_etx[0] != 0x03){
    // bad packet, try to read again 
    return(readCommand());
  }

  // convert hex characters into integers and add to struct 
  struct packet p;
  p.commandNumber = StrToHex(b1_cmd);
  p.objectID      = StrToHex(b2_id);
  p.data          = StrToHex(b34_data);

  return(p);
}

int StrToHex(char str[])
{
  // convert unsigned hex string into integer
  return (int) strtoul(str, 0, 16);
}