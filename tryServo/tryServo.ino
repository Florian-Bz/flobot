#include <Servo.h>

// create servo objects to control the servos (twelve servo objects can be created on most boards)
Servo joint0; // Base
Servo joint1; // Shoulder
Servo joint2; // Elbow

// defining arduino pwm pin numbers for each motor
int pin0 = 9; // Base
int pin1 = 10; // Shoulder
int pin2 = 11; // Elbow

// defining joint angles [deg]
int theta0 = 90; // Base
int theta1 = 90; // Shoulder
int theta2 = 90; // Elbow

void setup() 
{
  // attach the servo pins to the servo objects
  joint0.attach(pin0);  
  joint1.attach(pin1);
  joint2.attach(pin2);

  // call function to adjust position

  // move to home pos
  joint0.write(theta0);
  joint1.write(theta1);
  joint2.write(theta2);

  delay(1000);
  move_to(0, 15); // pos(0-180), speed(0-30)
}


void loop() 
{ 
  // joint0.write(0); //command to rotate the servo to the specified angle (range: 0-180)
  // delay(2000);
  // joint0.write(90);
  // delay(2000);
  // joint0.write(180);
  // delay(2000);
  // joint0.write(90);
  // delay(2000);
}


void move_to(int position, int speed) // passing an object as a function param
{
  int currentPos = joint0.read(); // read motor angle [deg]
  speed = map(speed, 0, 30, 30, 0); // map(value, fromCurrentLow(speed), fromCurrentHigh(speed), toTargetLow(time), toTargetHigh(time))
  if (position > currentPos) {
    for (; currentPos <= position; currentPos += 1) {
      joint0.write(currentPos);
      //theta0 = currentPos;
      delay(speed);
    }
  }
  else {
    for (; currentPos >= position; currentPos -= 1) {
      joint0.write(currentPos);
      //theta0 = currentPos;
      delay(speed);
    }
  }
}


// int read_angle(join)