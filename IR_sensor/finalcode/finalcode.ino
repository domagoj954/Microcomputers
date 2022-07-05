#include <SharpIR.h>
#include <LiquidCrystal.h>


#define ir A0
#define model 1080
LiquidCrystal lcd(0, 1, 10, 11, 12, 13);

int piezo = 4;
int led1 = 2;
int led2 = 3;
int led3 = 5;
int led4 = 8; 
int led5 = 9;
int i;
int val;
int redpin=0;


void setup()
{
  pinMode(redpin,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(piezo, OUTPUT);
   lcd.begin(16, 2);

}


void loop(){

 
  i=analogRead(redpin);
  val=(6762/(i-9))-4.2;
  lcd.print(val);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(val);
  lcd.print(" cm  ");
  delay(250);
     if(val >= 9){
     digitalWrite(2,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(5,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);

  }
     if (val == 8){
     digitalWrite(2,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(5,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
    }
   if(val == 7){
     digitalWrite(2,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
  }
   if (val == 6){
     digitalWrite(2,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(8,HIGH);
     digitalWrite(9,LOW);
   }
     if(val <= 5 ){
     digitalWrite(2,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(8,HIGH);
     digitalWrite(9,HIGH);
     tone(piezo, 500, 1000);
     lcd.setCursor(0, 1);
        lcd.print("WARNING!        ");   
        
     }
  else {
    lcd.clear();
}
} 

    
 
