// Variables

// Link lengths
int l1 = 200, l2 = 200; // [mm]

// Joint angles (base,shoulder,elbow)

// Base
float theta_b; // [deg]
float theta_d_b; // [deg/s] 
float theta_dd_b; // [deg/s^2]

// Shoulder
float theta_s; // [deg]
float theta_d_s; // [deg/s] 
float theta_dd_s; // [deg/s^2]

// Elbow
float theta_e; // [deg]
float theta_d_e; // [deg/s] 
float theta_dd_e; // [deg/s^2]

// EEF coordinates (x,y,z)
//int eef_coords[3];
int x;
int y;
int z;


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello");
  delay(1000); // [ms]
}

void DK(int theta_1, int theta_2, int &x, int &y) {
  // Direct kinematics (input: joint angles | output: eef coords)
  x = l1*sin(theta_1) + l2*sin(theta_1+theta_2);
  y = l1*cos(theta_1) + l2*cos(theta_1+theta_2);
}

void IK() {
  // Inverse kinematics (input: eef coords | output: joint angles)

}