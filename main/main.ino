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

void DK(float theta_s, float theta_e, float &x, float &y) {
  // Direct kinematics (input: joint angles | output: eef coords)
  x = l1*sin(theta_s) + l2*sin(theta_s+theta_e);
  y = l1*cos(theta_s) + l2*cos(theta_s+theta_e);
}

void IK(float x, float y, float &theta_s, float &theta_e) {
  // Inverse kinematics (input: eef coords | output: joint angles)
  float radius = sqrt(x*x + y*y); // distance from the origin to the eef
  float theta = atan2(x,y); // angle from x-axis to the radius
  float cos_beta = (radius*radius - l1*l2 - l2-l2) / (-2 * l1 * l2)  // internal angle btw links

  float beta;
  if (cos_beta < -1.0) {
    beta = PI; }
  else if (cos_beta > 1.0) {
    beta = 0.0; }
  else {
    beta = acos(cos_beta); }


}