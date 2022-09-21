
#include "EEPROM.h"
#include <Servo.h>
//Servo Defines for Steering
#define LEFT 50
#define STRAIGHT 90
#define RIGHT 130
//ESC Defines for Drive
#define NEUTRAL 1500
#define FORWARD_MAX 2000
#define REVERSE_MAX 1000
//Servo Object for Steering
Servo steering;
//Servo Object for Drive
Servo drive;
//Servo Object for Ultrasonic Servo
Servo ultrasonic_servo;
//Variable Declaration
int incomingByte = 0;  // for incoming serial data
//Pin Declaration
static int drivePin      =  2;
static int steeringPin   =  3;
static int trigPin       =  5;
static int echoPin       =  6;
static int ultrasonicPin =  7;
static int ledPin        =  4;
//Setup Function (Happens once)
void setup()
{
  //Setup Serial Sync
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  //Setup Steering
  steering.attach(steeringPin);
  //Setup Drive
  drive.attach(drivePin);
  //Setup Ultrasonic Servo
  ultrasonic_servo.attach(ultrasonicPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(trigPin, LOW);
}
//Loop (Keeps happening)
void loop()
{
  while (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    //Normally Steer Straight
    int steering_value=STRAIGHT;
    //Set Steering
    steering.write(steering_value);
    //Get Drive Speed
    int speed_value=50;//40 is too slow
    //Ensure Speed is Between 0 and 255
    if(speed_value<0)
      speed_value=0;
    if(speed_value>255)
      speed_value=255;
    //Drive Forward
    if(incomingByte == '2'){
      Serial.print("I received: 8, forward, ");
      Serial.println(incomingByte, DEC);
      drive.writeMicroseconds(map(speed_value,0,255,NEUTRAL,FORWARD_MAX));
    }
    //Drive Reverse
    if(incomingByte == '8'){
      incomingByte=Serial.read();
      Serial.print("I received: 2, reverse, ");
      Serial.println(incomingByte, DEC);
      drive.writeMicroseconds(map(speed_value,0,255,NEUTRAL,REVERSE_MAX));
    }
    //Drive Neutral
    if(incomingByte == '0'){
      incomingByte=Serial.read();
      Serial.print("I received: 2, neutral, ");
      Serial.println(incomingByte, DEC);
      drive.writeMicroseconds(NEUTRAL);
    }
    //Steering Left
    if(incomingByte == '7'){
      incomingByte=Serial.read();
      Serial.print("I received: 2, neutral, ");
      Serial.println(incomingByte, DEC);
      steering.write(LEFT);
    }
    //Steering Straight
    if(incomingByte == '5'){
      incomingByte=Serial.read();
      Serial.print("I received: 2, neutral, ");
      Serial.println(incomingByte, DEC);
      steering.write(STRAIGHT);
    }
    //Steering Right
    if(incomingByte == '9'){
      incomingByte=Serial.read();
      Serial.print("I received: 2, neutral, ");
      Serial.println(incomingByte, DEC);
      steering.write(RIGHT);
    }
    //Automode on
    /*    if(incomingByte == 'y'){
     boolean runs = true;
     */
    while(incomingByte == 'y')
    {
      incomingByte=Serial.read();
      Serial.print("Automode on");
      Serial.println(incomingByte, DEC);
      digitalWrite(ledPin, HIGH);
      //UltraSonic Sensor
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      long duration = pulseIn(echoPin, HIGH);
      long distance = (duration/2) / 29.1;
      Serial.print(distance);
      Serial.println(" cm");    
      int i=20;
      while(i<=120)
      {
        ultrasonic_servo.write(i);
        delay(15);
        if(distance<20)
        {
          Serial.print(i);
          steering.write(i);  
          delay(50);
          break;
          //i++;
        }
        else 
        {
          i=i+1;
          Serial.println("Moving Forward Bossman");
          //          drive.writeMicroseconds(map(speed_value,0,255,NEUTRAL,FORWARD_MAX));
        }
      }
      delay(1000);
    } 
    //Automode off  
    if(incomingByte == 'n'){
      incomingByte=Serial.read();
      Serial.print("Automode off");
      Serial.println(incomingByte, DEC);
      digitalWrite(ledPin, LOW);
    } 
  }
}

