// Variables

// Link lengths
int l1 = 200, l2 = 200; // [mm]

/**
theta_b (base)
theta_s (shoulder)
theta_e (elbow)
theta_w (wrist)
**/

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

int DK(int theta_s, int theta_e) {
  // Direct kinematics (input: joint angles | output: eef coords)
  int x = l1*sin(theta_s) + l2*sin(theta_s+theta_e);
  int y = l1*cos(theta_s) + l2*cos(theta_s+theta_e);
  return x, y;
}

void IK() {
  // Inverse kinematics (input: eef coords | output: joint angles)

}