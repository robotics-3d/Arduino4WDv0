/*
  Nome: BeginnerKit4WD.ino
  -------------------------------------------------------------
  Libreria per gestire i motori shield L298P v.1.2 DFROBOT
  -------------------------------------------------------------
  Autore : Ferrarini Fabio - www.robotics-3d.com
           www.artigianitecnologici.it
  Data   : 27/09/2014
  Revisione : 
*/


// Servo
// Red ---> 5V
// Brown ---> GND
// Yellow ---> D10

// Ultrasonic Sensor
// Red ---> 3.3V
// Black ---> GND
// Yellow ---> A5
// Impostato ad 1 abilita il livello di debug
int debug = 1; //1 on 0 Off


#include "pitches.h"  
#include <Servo.h> // Includiamo la libreria Servo per controllare quest'ultimo

const int audioPin = 13;  // Audio
const int signalPin = 12; 
const int echoPin = 11;
const int PinServo = 10; // Pin dove è collegato il servo (dovrà essere un pin che supporta la modalità PWM)

// Pin shield Motori 
const int E1 = 5; 
const int M1 = 4;
const int E2 = 6;                     
const int M2 = 7;  

#define SENSOR_MIN_DIST 40
#define SENSOR_MAX_DIST 200

#define HI_SPEED 255
#define LO_SPEED 255

Servo servo; // Dichiariamo la classe Servo come mioservo

int SensorValue;
int SensorLeft;
int SensorRight;

int pos,i;

int centro = 45;
int destra = 90;
int sinistra = 15; 

int velocita = LO_SPEED;// Qui modifichiamo la velocità del robot
int distanza_massima = SENSOR_MAX_DIST;
   
void setup()
{
    Serial.begin(9600); 
    
    servo.attach(PinServo); // Inizializziamo il servo al pin 10
    servo.write(centro);
    PlayMelody();           // suona una melodia
   
}
 
// Loop principale
// ----------------------------------
void loop()
{
  
  long ping = getDistance();
  int dir;
  Serial.print("distanza :");
  Serial.println(ping);
  // Se la distanza rilevata e maggiore alla dist.minima
  if ( ping > SENSOR_MIN_DIST ) {
     MotorAvanti(velocita);
  }
  // Se minore
  if ( ping <= SENSOR_MIN_DIST ) {
      MotorStop();
      delay(20);
      dir = guarda();
      MotorIndietro(velocita);
      delay(650);
      MotorStop();
      if (dir == 1) {
          //Serial.println(“Destra e bloccato giro a sinistra”);
          MotorSinistra(velocita);
          delay(2000);
          MotorStop();
          
      } else  {
         // Serial.println(“sinistra e bloccato vado a destra”);
          MotorDestra(velocita);
          delay(2000);
          MotorStop();
      }
      
  }

   
     
}
  

int guarda()
{
  servo.write(destra);
  long pingdx = getDistance();
  Serial.print("Guardo DX: ");
  Serial.println(pingdx,DEC);
  delay(1000);
  servo.write(sinistra);
  long pingsx = getDistance();
  Serial.print("Guardo SX: ");
  Serial.println(pingsx,DEC);
  delay(1000);
  servo.write(centro);
 // long pingce = getDistance();
 // Serial.print("Guardo centro: ");
 // Serial.print(pingce,DEC);
  
  if ( pingdx <= pingsx ) {
    return 1;
    } else {
     return 2;
     } 
/*
  if ( pingdx <= SENSOR_MIN_DIST ) {
    return 1;
  }
  if ( pingsx <= SENSOR_MIN_DIST ) {
    return 2;
  }
  */
}
    
    
void movimento_servo(int x)
{
  switch (x) {
    case 0:
      servo.write(centro);  // Rimani al centro
      break;
    case 1:
      servo.write(destra); // Gira a destra
      break;
    case 2:
      servo.write(sinistra);  // Gira a sinistra
      break;
  }
}

    
    



  
