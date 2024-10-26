/* This example shows how to take
range measurements with the VL53L0X and display on a SSD1306 OLED.

The range readings are in units of mm. */

#include <Wire.h>
#include "Adafruit_VL53L0X.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306();

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#if (SSD1306_LCDHEIGHT != 32)
 #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Set the origin in the middle of the display
int yii = 0;
int xii = 0;
int aii = 0;
int bii = 0;
int cii = 0;

int rangernd = 1;
int range = 1;

void setup()
{
  Serial.begin(9600);
    
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display();
  delay(1000);
    
  
  Wire.begin();

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  // text display big!
  display.setTextSize(4);
  display.setTextColor(WHITE);
}


void randplus(){
  rangernd = 1+random(0,5);
}

void randminus(){
  rangernd = 1-random(0,5);
}


void ranger()
{
  VL53L0X_RangingMeasurementData_t measure;
display.clearDisplay();
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      
for(int i = 0; i <= 128; i++){
switch (random(1,2)) {
        //select size of phrase
        case 1:randplus(); break;
        case 2:randminus(); break;
        }
xii=1;
yii=1;
aii=3000;
//aii=measure.RangeMilliMeter;
bii=127;
cii=64;

xii = sq(i-cii);
yii = (aii/(bii+xii));
yii = yii +rangernd;

display.drawPixel(i, (yii+2), SSD1306_WHITE );
//display.drawFastVLine(i,0,yii,SSD1306_WHITE );
i=i+4;

Serial.print(" a ");
Serial.print(a);
Serial.print(" b ");
Serial.print(b);
Serial.print(" c ");
Serial.print(c);
Serial.print(" x ");
Serial.print(x);
Serial.print(" i ");
Serial.print(i);
Serial.print(" y ");
Serial.println(y);


}
display.display();


}}