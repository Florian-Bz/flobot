#include <Servo.h>

// create servo objects to control the servos (twelve servo objects can be created on most boards)
Servo joint0; // Base
Servo joint1; // Shoulder
Servo joint2; // Elbow

// Defining arduino pwm pin numbers for each motor
int pin0 = 9; // Base
int pin1 = 10; // Shoulder
int pin2 = 11; // Elbow

int angle = 0;

void setup() 
{
  //Serial.begin(9600);
  joint0.attach(pin0);  // attaches the servo on pin 9 to the servo object
  //joint0.write(90);
}


void loop() 
{ 
    // joint0.write(0);              	 //command to rotate the servo to the specified angle
    // delay(2000);  
    // joint0.write(90);              	 //command to rotate the servo to the specified angle
    // delay(2000);  
    // joint0.write(180);              	 //command to rotate the servo to the specified angle
    // delay(2000);  


  for(angle = 0; angle < 180; angle += 1) 	 // command to move from 0 degrees to 180 degrees 
  {                                  
    joint0.write(angle);              	 //command to rotate the servo to the specified angle
    delay(10);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    joint0.write(angle);              //command to rotate the servo to the specified angle
    delay(10);                       
  } 

    delay(1000);

}