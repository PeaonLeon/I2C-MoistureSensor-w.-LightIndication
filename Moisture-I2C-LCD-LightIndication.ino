#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ledRed = 13;
int ledGreen = 12;
void setup()
{
	pinMode (ledRed, OUTPUT);
	pinMode (ledGreen, OUTPUT);
	
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Moisture Sensor");
}

void loop()
{
	
	if (analogRead(A1)<480){
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
} else {
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
}
	
	
	
	int val;                 //sets a variable
  val = analogRead(1);
  lcd.setCursor(0, 1);     //sets the cursor to the second Row
  lcd.print(analogRead(1));    //prints the value
  delay(10000);                //10 sec delay
}
