#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x3E			//Address of the LCD you are using, change it to yours

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif


byte x,y,z;					// Variables which we read from master
// Function that executes whenever data is received from master
// This function is registered as an event, see setup()
void receiveEvent(int msg_length) {
  while (1 < Wire.available()) { // Loop while master is sending something
    x = Wire.read();				// Read first digit
    y = Wire.read();				// Read second digit
    z = Wire.read();				// Read third digit
    delay(100);
  }
}

//Making custom characters, 8 of them is maximum, so we made it so every number can be made with combination of these 8 parts
byte bar1[8] = 
{
        B11110,
        B11110,
        B11110,
        B11110,			// 1's will be shown on the lcd, 0's aren't on
        B11110,
        B11110,
        B11110,
        B11110
};
byte bar2[8] =
{
        B01111,
        B01111,
        B01111,
        B01111,			// 1's will be shown on the lcd, 0's aren't on
        B01111,
        B01111,
        B01111,
        B01111
};
byte bar3[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar4[8] =
{
        B11110,
        B11110,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B11110,
        B11110
};
byte bar5[8] =
{
        B01111,
        B01111,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B01111,
        B01111
};
byte bar6[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar7[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B01111,
        B01111
};
byte bar8[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,			// 1's will be shown on the lcd, 0's aren't on
        B00000,
        B00000,
        B00000,
        B00000
};


void custom0(int col)
{ // Uses segments to build numbers/letters, in this case numbers from 0 to 9
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom1(int col)
{
  lcd.setCursor(col,0);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col,1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

void custom4(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom9(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}
	// Function which determines which number we are going to print and in which col
void printNumber(int value, int col) {
  if (value == 0) {
    custom0(col);
  } if (value == 1) {
    custom1(col);
  } if (value == 2) {
    custom2(col);
  } if (value == 3) {
    custom3(col);
  } if (value == 4) {
    custom4(col);
  } if (value == 5) {
    custom5(col);
  } if (value == 6) {
    custom6(col);
  } if (value == 7) {
    custom7(col);
  } if (value == 8) {
    custom8(col);
  } if (value == 9) {
    custom9(col);
  }      
}  

LiquidCrystal_I2C lcd(LCD_ADDRESS,16,2);

void setup()
{
  lcd.init();			// Defining lcd for usage
  lcd.backlight();		// Activating lcd's backlight

  Wire.begin(1); 		// Start the i2c, taking the address of 1 (slaves must have an address, masters nope)
  Wire.onReceive(receiveEvent); // When slave recieves signal from the master, recieveEvent happens
       
				// Making the segments possible to use with createChar
  lcd.createChar(1,bar1);
  lcd.createChar(2,bar2);
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);

				// Using segments to make letter E 
  lcd.setCursor(0, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(3);
  lcd.setCursor(0, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(6);
				// Using segments to make letter P
  lcd.setCursor(3, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(3, 1);  
  lcd.write(2);  
  
  while(1){
   printNumber(x, 7);		//Printing digit x, starting on col 7
   printNumber(y, 10);		//Printing digit y, starting on col 10
   printNumber(z, 13);		//Printing digit z, starting on col 13
    delay(1000);
  }
}



