// Variables

// Link lengths
int l1 = 200, l2 = 200; // [mm]

// Joint angles (base,shoulder,elbow)
int joint_angles[3];

// EEF coordinates (x,y,z)
int eef_coords[3];


/**
theta_b (base)
theta_s (shoulder)
theta_e (elbow)
**/

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello");
  delay(1000); // [ms]
}

void DK(int &theta_1, int &theta_2, int &x, int &y) {
  // Direct kinematics (input: joint angles | output: eef coords)
  x = l1*sin(theta_1) + l2*sin(theta_1+theta_2);
  y = l1*cos(theta_1) + l2*cos(theta_1+theta_2);
}

void IK() {
  // Inverse kinematics (input: eef coords | output: joint angles)

}