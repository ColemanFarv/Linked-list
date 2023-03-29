/******************************************************************************
FILENAME:     lab_1_1.ino
COURSE:       MREN 178
LAB:          1
STUDENT(S):   [Hannah Vibien 20332596 and Coleman Farvolden 20335398]
DATE:        

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE]

******************************************************************************/
// include the library code:
#include <LiquidCrystal.h>
//initializing global variables
int number = 100;//100 is the starting value each time the program is reset
int flag = 0;//will control programs execution
int i = 0;//set i equal to 0

int a[5];//declaring an array of 5

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
  lcd.print("number:");//print "number:" to the LCD
  lcd.setCursor(0,1);//set cursor to coloumn 1 row 2
  lcd.print(number);//print value of number on LCD
  Serial.println(100);//print starting value of 100 to serial monitor
 
}

void loop() {
  int x;//Declare local variable
 
  x = analogRead (0);//initialize x to analogRead value
  lcd.setCursor(10,1);//set cursor to column 11, row 2

  //Create if statements to choose what to print to the LCD
  if (x < 60 && flag == 0) {//if x is smaller than 60 and the flag is 0, run this code
 
      number = number + 1;//add one to the number value and set that new value to be the number value
      Serial.println(number);//print value of number to serial monitor
      flag = 1;//set flag to be 1
      lcd.setCursor(0,1);//set cursor to column 1, row 2
      lcd.print(number);//print the value of the number to the display
      lcd.print("        ");//add spaces after printing the number
  }
   if (x < 200 && flag == 0) {//if x is smaller than 200 and the flag is 0, run this code

      number = number + 10;//add ten to the number value and set that new value to be the number value
      flag = 1;//set flag to be 1
      Serial.println(number);//print value of number to serial monitor
      lcd.setCursor(0,1);//set cursor to column 1, row 2
      lcd.print(number);//print the value of the number to the display
      lcd.print("        ");//add spaces after printing the number

  }
   if (x < 400 && flag == 0){//if x is smaller than 400 and the flag is 0, run this code

      number = number - 10;//subtract ten from the number value and set that new value to be the number value
      flag = 1;//set flag to be 1
      Serial.println(number);//print value of number to serial monitor
      lcd.setCursor(0,1);//set cursor to column 1, row 2
      lcd.print(number);//print the value of the number to the display
      lcd.print("        ");//add spaces after printing the number
  }
   if (x < 600 && flag == 0){//if x is smaller than 600 and the flag is 0, run this code
   
      number = number - 1;//subtract 1 from the number value and set that new value to be the number value
      flag = 1;//set flag to be 1
      Serial.println(number);//print value of number to serial monitor
      lcd.setCursor(0,1);//set cursor to column 1, row 2
      lcd.print(number);//print the value of the number to the display
      lcd.print("        ");//add spaces after printing the number
  }
   if (x < 800 && flag == 0){//if x is smaller than 800 and the flag is 0, run this code
   
      int w = 0;//initialize w to 0;
      if(i < 5){//if i is smaller than 5, set the numbers value to the array index value of i
        a[i] = number;
        i++;//add one to the value of i each time through
}

    if(i>4){//if i is bigger than 4
      Serial.println("Array Full");//print text of to serial monitor
      lcd.setCursor(0,1);//set cursor to column 1, row 2
      lcd.print("Array Full");//print text to LCD
}
      Serial.println(" ");//add spaces after printing the text
 
    while(w < 5){//while w is smaller than 5, print each arrays index value to the serial monitor
      Serial.print(a[w]);
      Serial.print(" ");
      w++;//add one to the value of w each time through  
}
    Serial.println(" ");//add spaces after printing the text
    flag = 1;//set flag to be 1
   
  }
  if (x > 1000){//if nothing else runs, set flag=0. Do not print anything while the analogRead value is greater than 1000 (until a button is pressed)
flag = 0;
  }

}
