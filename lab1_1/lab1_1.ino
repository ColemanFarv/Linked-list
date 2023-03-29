/******************************************************************************
FILENAME:     lab_1_1.ino
COURSE:       MREN 178
LAB:          1
STUDENT(S):   [Hannah Vibien 20332596, Coleman Farvolden 20335398 ]
DATE:        

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE]

******************************************************************************/
// include the library code:
#include <LiquidCrystal.h>
//initializing global variables
int number = 100; //100 is the starting value each time the program is reset
int flag = 0;//will control programs execution
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to      
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;
LiquidCrystal lcd(pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

void setup() {
  //what is to be displayed on the LCD
  Serial.begin(9600);
  lcd.begin(16, 2);//display size is 16 columns and 2 rows
  lcd.setCursor(0,0);//coloumn 1, row 1
  lcd.print("number:");//print the word "number:" to the LCD
 
}

void loop() {
  int x;//Declar variable
 
  x = analogRead (0);//initialize x to analogRead value
  Serial.println(x);//print value of analogRead to serial monitor
  lcd.setCursor(10,1);//set cursor to column 11, row 2

//Create if statements to choose what to print to the LCD
 
  if (x < 60 && flag == 0) {//if x is smaller than 60 and the flag is 0, run this code
 
    number = number + 1;//add one to the number value and set that new value to be the number value
    flag = 1;//set flag to be 1
  }
  else if (x < 200 && flag == 0) {//if x is smaller than 200 and the flag is 0, run this code

    number = number + 10;//add ten to the number value and set that new value to be the number value
    flag = 1;//set flag =1;
  }
  else if (x < 400 && flag == 0){//if x is smaller than 400 and the flag is 0, run this code

    number = number - 10;//subtract 10 from the number value and set that new value to be the number value
    flag = 1;//set flag =1;
  }
  else if (x < 600 && flag == 0){//if x is smaller than 600 and the flag is 0, run this code
   
     number = number - 1;//subtract one from the number value and set that new value to be the number value
     flag = 1;//set flag =1;
  }
  else if (x < 800){//if x is smaller than 600 run this code
    lcd.print ("Select");//print Select to the LCD
   
  }

  else{
flag = 0;//if nothing else runs, set flag=0. Do not print anything while the analogRead value is greater than 800 (until a button is pressed).
  }

  lcd.setCursor(0,1);//set cursor to column 1 row 2
  lcd.print(number);//print the value of the number to the display
  lcd.print("      ");//add spaces after printing the number
}
