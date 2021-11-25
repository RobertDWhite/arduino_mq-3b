/*
 LCD with i2c/SPI LCD backpack from Adafruit
 using MCP23008 I2C expander
 ( http://www.ladyada.net/products/i2cspilcdbackpack/index.html )

  The circuit from digital display backpack:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * DAT to Analog #4
 * CLK to Analog #5

 Alcohol MQ3 sensor
*/

// include the library code:
//this is the i2C sketch
#include "Wire.h"
//this is the LCD sketch
#include "Adafruit_LiquidCrystal.h"

// Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal lcd(0);

//mq3 connect to A0
int mq3_analogPin = A0;
int mq3_value = 0;

void setup() {
  // set up the LCD's number of rows and columns:
  lcd.begin(16, 2);
  // turn off the backlight
  lcd.setBacklight(HIGH);
  // Print the units to the LCD.
  lcd.print("Volts =");
  Serial.begin(9600);
}

void loop() {
  //read the A0 pin for the MQ3 output
  int mq3_value = analogRead(mq3_analogPin);
  //convert the 0-1256 reading to a decimal
  float mq3_volt = mq3_value * 0.0048;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since value separated from units):
  lcd.setCursor(0, 1);
  // print the MQ3 voltage reading:
  lcd.print(mq3_volt);
}
