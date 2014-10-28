/*
  Nome: motor.ino
  -------------------------------------------------------------
  Libreria per gestire i motori shield L298P v.1.2 DFROBOT
  -------------------------------------------------------------
  Autore : Ferrarini Fabio - www.robotics-3d.com
           www.artigianitecnologici.it
  Data   : 27/09/2014
  Revisione :
*/
void MotorAvanti(int speed)
{
  int vel = map(speed, 0, 100, 0, 255);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,HIGH);
  analogWrite(E1, vel);   
  analogWrite(E2, vel); 

   
   
  }
  
void MotorIndietro(int speed)
{
  int vel = map(speed, 0, 100, 0, 255);
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  analogWrite(E1, vel);   
  analogWrite(E2, vel); 
 
   
  }
void MotorStop()
{
 
   analogWrite(E1,0);
   analogWrite(E2,0);
   
  }
  
void MotorSinistra(int speed)
{
  int vel = map(speed, 0, 100, 0, 255);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  analogWrite(E1, vel);   
  analogWrite(E2, vel);
  
  }
void MotorDestra(int speed)
{
  int vel = map(speed, 0, 100, 0, 255);
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  analogWrite(E1, vel);   
  analogWrite(E2, vel); 
   
  }
