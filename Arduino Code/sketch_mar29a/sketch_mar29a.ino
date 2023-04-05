#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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
  readCommand();
  delay(1000);
}

void readCommand(){
  // start and end packet characters
  char start_stx = 0x02;
  char end_etx = 0x03;

  // init strings
  char b0_stx[1];
  char b1_cmd[1];
  char b2_id[1];
  char b34_data[2];
  char b6_etx[1];
  
  // read until STX found, which marks the start of a data packet
  bool started = false;
  while(started == false){
    b0_stx[0] = Read();
    if(b0_stx[0] == start_stx){
      started = true;
    }
  }
  
  // then read 5 bytes
  b1_cmd[0]   = Read();
  b2_id[0]    = Read();
  b34_data[0] = Read();
  b34_data[1] = Read();
  b6_etx[0]   = Read();

  // verify that last byte is ETX, which ends the packet

  // convert hex characters into integers 
  int cmd  = StrToHex(b1_cmd);
  int id   = StrToHex(b2_id);
  int data = StrToHex(b34_data);

  // return packet data
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(cmd);
  display.println(id);
  display.println(data);
  display.display(); // temp. display for now 
}

char Read(){
  while(Serial.available() > 0){
    return Serial.read();
  }
  return '\0';
}

int StrToHex(char str[]) // hmmm I dont think this is working 
{
  return (int) strtoul(str, nullptr, 16);
}