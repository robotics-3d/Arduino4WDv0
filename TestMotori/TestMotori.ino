/*
  Nome: TestMotori.ino
  -------------------------------------------------------------
  Libreria per gestire i motori shield L298P v.1.2 DFROBOT
  -------------------------------------------------------------
  Autore : Ferrarini Fabio - www.robotics-3d.com
           www.artigianitecnologici.it
  Data   : 27/09/2014
  Revisione :
*/
int E1 = 5; 
int M1 = 4;
int E2 = 6;                     
int M2 = 7;                       
 
void setup()
{
     Serial.begin(9600); 
    pinMode(M1, OUTPUT);  
    pinMode(M2, OUTPUT);
}
 
void loop()
{
  Serial.println("Avanti ");
  int value;
  for(value = 100 ; value <= 255; value+=5)
  
  {
    digitalWrite(M1,HIGH);  
    digitalWrite(M2, HIGH);      
    analogWrite(E1, value);   //PWM Speed Control
    analogWrite(E2, value);   //PWM Speed Control
    delay(30);
  } 
  delay(3000);
  Serial.println("Indietro");
  for(value = 100 ; value <= 255; value+=5)
  {
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  analogWrite(E1, value);   //PWM Speed Control
    analogWrite(E2, value);   //PWM Speed Control
    delay(30);
  } 
  delay(3000);
}
