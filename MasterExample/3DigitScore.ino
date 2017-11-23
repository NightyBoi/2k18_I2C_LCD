#include <Wire.h>

void setup() {
  Wire.begin(); 				      // Join i2c bus (address optional for master)
}

int score = 650;              // Change to any number you want to display

void loop() {
  byte x,y,z;                 // Three variables in which we store every digit seperately (since max byte value is 127)
  x=score/100;
  y=(score/10)%10;
  z=score%10;
  
  Wire.beginTransmission(1); 	// Transmit to device #1
  Wire.write(x);            	// Sends first score digit
  delay(100);
  Wire.write(y);			      	// Sends second score digit
  delay(100); 
  Wire.write(z); 				      // Sends third score digit
  Wire.endTransmission();    	// Stop transmitting
  
 
  delay(500);
}
