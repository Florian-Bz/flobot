int pin0Pot = A0; // Base potentiometer pin
int pin1Pot = A1; // Shoulder potentiometer pin
int pin2Pot = A2; // Elbow potentiometer pin

float pot0Val; // Base potentiometer value
float pot1Val; // Shoulder potentiometer value
float pot2Val; // Elbow potentiometer value

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits/sec
}

void loop() {

  pot0Val = analogRead(pin0Pot); // read the input on analog pin 0
  float motorPos = knobToAngle(pot0Val);


  Serial.println("potVal"); // print the read value
  Serial.println(pot0Val); // print the read value

  Serial.println("motorPos"); // print the read value
  Serial.println(motorPos); // print the read value

  delay(500);

}

// convert potentiometer value to motor angle
float knobToAngle(float potVal) {
  float motorAngle = (180./1023.)*potVal;
  return motorAngle;
}