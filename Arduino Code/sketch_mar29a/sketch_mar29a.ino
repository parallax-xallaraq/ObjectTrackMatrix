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
  int r1 = Serial.read();
  int r2 = Serial.read();
  int r3 = Serial.read();
  int r4 = Serial.read();
  int r5 = Serial.read();
  int r6 = Serial.read();
  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(r1);
  display.println(r2);
  display.println(r3);
  display.println(r4);
  display.println(r5);
  display.println(r6);
  display.display();
  
  delay(1000);
}

void GenerateRand(){
  
  int n = random(10);

  display.clearDisplay();
  display.setCursor(0,20);             
  display.println(n);
  display.display();
  
  Serial.write(n);
  
  delay(1000);
}
