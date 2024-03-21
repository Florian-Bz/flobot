#include <Servo.h>

Servo joint1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos; // variable to store the servo position
bool newData = false; // check if there is a new command on the serial port



void setup() 
{
  Serial.begin(9600);
  joint1.attach(9);  // attaches the servo on pin 9 to the servo object

  Serial.println("Enter the desired joint angle [deg]: ");
}


void loop() 
{
  // If something is input in the serial by the user
  if (Serial.available() > 0);
    {
      // Read the angle and store it
      pos = Serial.read();
      Serial.println("pos: ");
      Serial.println(pos);
      // Move the motor
      joint1.write(pos);
    } 
}

