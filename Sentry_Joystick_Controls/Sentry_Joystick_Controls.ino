#define RPWM1 10//left Rpwm1
#define LPWM1 11 //left Lpwm1
//right motor
#define RPWM2 6 //left Rpwm1
#define LPWM2 5 //left Lpwm1

const int joystickXPin = A0; // joystick X-Axis Pin
const int joystickYPin = A1; // joystick Y-Axis Pin

void setup() {
  Serial.begin(9600);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);

}

void loop() {
  int joystickX = analogRead(joystickXPin);
  int joystickY = analogRead(joystickYPin);

  //condition1 True, condtion2 True
  if (joystickX >= 520 && joystickX <= 525 && joystickY >= 533 && joystickY <= 536) {
    Serial.println("Steady");
    analogWrite(RPWM1, 0);
    analogWrite(LPWM1, 0);
    analogWrite(RPWM2, 0);
    analogWrite(LPWM2, 0);
  }

  //condition 1 True, Condition2 True
  // Forward
  else if (joystickX >= 520 && joystickX <= 525 && joystickY <= 535 && joystickY >= 0) {
    Serial.println("Forward");
    int motorSpeed = map(joystickY, 535, 0, 0, 255); // Map joystickY to PWM range (0-255)
    analogWrite(RPWM1, motorSpeed);
    analogWrite(LPWM2, motorSpeed);
  }
  // Backward
  else if (joystickX >= 520 && joystickX <= 525 && joystickY >= 535 && joystickY <= 1023) { //>=
    Serial.println("Backward");
    int motorSpeed = map(joystickY, 535, 1023, 0, 255); // Map joystickY to PWM range (0-255)
    analogWrite(LPWM1, motorSpeed);
    analogWrite(RPWM2, motorSpeed);
  }
  //Left
  else if (joystickX >= 0 && joystickX <= 525 && joystickY >= 530 && joystickY <= 537) {
    Serial.println("Left");
    int motorSpeed = map(joystickX, 525, 0, 0, 255); // Map joystickY to PWM range (0-255)
    analogWrite(RPWM1, motorSpeed);

  }
  //Right

  else if (joystickX >= 520 && joystickX <= 1023 && joystickY >= 530 && joystickY <= 537){
    Serial.println("Right");
    int motorSpeed = map(joystickX, 520, 1023, 0, 255); // Map joystickY to PWM range (0-255)
    analogWrite(LPWM2, motorSpeed);
  }
//  else {
//    // X-Axis value
//    Serial.print("X: ");
//    Serial.print(joystickX);
//
//    // Y-Axis value
//    Serial.print(" Y: ");
//    Serial.println(joystickY);
//  }
  delay(100);
}
