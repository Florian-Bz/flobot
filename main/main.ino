#include <Servo.h>

// create servo objects to control the servos (twelve servo objects can be created on most boards)
Servo joint0; // Base
Servo joint1; // Shoulder
Servo joint2; // Elbow

// defining arduino pwm pin numbers for each motor
int pin0 = 9; // Base
int pin1 = 10; // Shoulder
int pin2 = 11; // Elbow

// defining joint angles [deg] --> array?
int theta0 = 90; // Base
int theta1 = 90; // Shoulder
int theta2 = 90; // Elbow

// defining potentiometer pins
int pin0Pot = A0; // Base potentiometer pin
int pin1Pot = A1; // Shoulder potentiometer pin
int pin2Pot = A2; // Elbow potentiometer pin

// defininig potentiometer read values
float pot0Val; // Base potentiometer value
float pot1Val; // Shoulder potentiometer value
float pot2Val; // Elbow potentiometer value


void setup() {
  // move robot to home pos at startup
  home_pos(90);

  // attach the servo pins to the servo objects
  joint0.attach(pin0);
  joint1.attach(pin1);
  joint2.attach(pin2);

  delay(1500);

  // call function to adjust position
  // move_to(joint0, 135, 15); // joint(0,1,2), pos(0-180), speed(0-30)
  // move_to(joint1, 135, 15); // joint(0,1,2), pos(0-180), speed(0-30)
  // move_to(joint2, 135, 15); // joint(0,1,2), pos(0-180), speed(0-30)

}


void loop() { 
  // joint0.write(0); //command to rotate the servo to the specified angle (range: 0-180)
  // delay(2000);

  // read potentiometer
  // write to motor
  
}


/**
Servo motors jump to 90 deg at startup by default.
To change this angel do a .write() with the desired angle before .attach()
*/
void home_pos(int homing_pos) {
  joint0.write(homing_pos);
  joint1.write(homing_pos);
  joint2.write(homing_pos);
}


/**
Move the motor to a desired position between 0-180 deg
and a desired speed ranging from min 0 to max 30.
*/
void move_to(Servo &joint, int position, int speed) {
  int currentPos = joint.read(); // read motor angle [deg]
  speed = map(speed, 0, 30, 30, 0); // map(value, fromCurrentLow(speed), fromCurrentHigh(speed), toTargetLow(time), toTargetHigh(time))
  if (position > currentPos) {
    for (; currentPos <= position; currentPos += 1) {
      joint.write(currentPos);
      delay(speed);
    }
  }
  else {
    for (; currentPos >= position; currentPos -= 1) {
      joint.write(currentPos);
      delay(speed);
    }
  }
}


/**
Convert potentiometer value to motor angle
*/
float knobToAngle(int motorID) {
  
  float potVal = analogRead(pinPot);
  float motorAngle = (180./1023.)*potVal;
  return motorAngle;
}
