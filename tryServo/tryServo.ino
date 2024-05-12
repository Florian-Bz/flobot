#include <Servo.h>

// create servo objects to control the servos (twelve servo objects can be created on most boards)
Servo joint0; // Base
Servo joint1; // Shoulder
Servo joint2; // Elbow

// defining arduino pwm pin numbers for each motor
int pin0 = 9; // Base
int pin1 = 10; // Shoulder
int pin2 = 11; // Elbow

int angle = 0;

void setup() 
{
  // attach the servo pins to the servo objects
  joint0.attach(pin0);  
  joint1.attach(pin1);
  joint2.attach(pin2);

  // move to home pos
  joint0.write(90);
  joint1.write(90);
  joint2.write(90);
}


void loop() 
{ 
  joint0.write(0); //command to rotate the servo to the specified angle (range: 0-180)
  delay(2000);  
  joint0.write(90);
  delay(2000);  
  joint0.write(180);
  delay(2000);  
}

void move_to(int position, int speed) // image is in the folder
{
  mapSpeed = map(speed, 0, 30, 30, 0);
  if (position > pos) {
    for (pos = pos1; pos <= position; pos += 1){
      joint
    }
  }

}