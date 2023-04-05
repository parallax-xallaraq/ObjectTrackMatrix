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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println("Hello, world!");
  display.display();
  delay(2000); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // char r1 = Serial.read();
  // char r2 = Serial.read();
  // char r3 = Serial.read();
  // char r4 = Serial.read();
  // char r5 = Serial.read();
  // char r6 = Serial.read();
  // display.clearDisplay();
  // display.setCursor(0,20);             
  // display.println(r1);
  // display.println(r2);
  // display.println(r3);
  // display.println(r4);
  // display.println(r5);
  // display.println(r6);
  // display.display();
  int * packet;
  packet = readCommand();
  delay(1000);
}

int * readCommand(){
  // start and end packet characters
  char start_stx = 0x02;
  char end_etx   = 0x03;

  // init strings
  char b0_stx[]   = "0";
  char b1_cmd[]   = "0";
  char b2_id[]    = "0";
  char b34_data[] = "00";
  char b6_etx[]   = "0";
  
  // read until STX found, which marks the start of a data packet
  bool started = false;
  while(!started && Serial.available() > 0){    
    // read a byte
    b0_stx[0] = Serial.read();
    // check if byte is STX
    if(b0_stx[0] == start_stx){
      started = true;

      // then read next 5 bytes
      b1_cmd[0]   = Serial.read();
      b2_id[0]    = Serial.read();
      b34_data[0] = Serial.read();
      b34_data[1] = Serial.read();
      b6_etx[0]   = Serial.read();

      // verify that last byte is ETX, which ends the packet
      if( b6_etx[0] != end_etx){
        readCommand();
      }

      // convert hex characters into integers 
      int cmd  = StrToHex(b1_cmd);
      int id   = StrToHex(b2_id);
      int data = StrToHex(b34_data);

      // return packet data
      display.clearDisplay();
      display.setCursor(0,20);             
      // display.println(b1_cmd);
      // display.println(b2_id);
      // display.println(b34_data);
      display.println(cmd);
      display.println(id);
      display.println(data);
      display.display();
      delay(1000);

      // combine
      int packet[3] = {cmd, id, data};
      return(packet);
    }
  }
  
  int badPacket[3] = {-1,-1,-1};
  return(badPacket);
}

int StrToHex(char str[]) // hmmm I dont think this is working 
{
  return (int) strtoul(str, 0, 16);
}