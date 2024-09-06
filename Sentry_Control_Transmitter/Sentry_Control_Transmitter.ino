#include <SoftwareSerial.h>
SoftwareSerial HC12(2, 3);

const int joystickXPin = A0; // joystick X-Axis Pin
const int joystickYPin = A1; // joystick Y-Axis Pin

const int tolerance = 5; // Tolerance value for joystick position

void setup() {
  Serial.b  egin(9600);
  HC12.begin(9600);
}

void loop() {
  int joystickX = analogRead(joystickXPin);
  int joystickY = analogRead(joystickYPin);

  // Steady position
  if (joystickX >= 505 - tolerance && joystickX <= 515 + tolerance && joystickY >= 515 - tolerance && joystickY <= 525 + tolerance) {
    Serial.println("Steady position");
  }
  // Forward
  else if (joystickX >= 505 - tolerance && joystickX <= 515 + tolerance && joystickY >= -tolerance && joystickY <= 10 + tolerance) {
    Serial.println("Forward");
  }
  // Backward
  else if (joystickX >= 505 - tolerance && joystickX <= 515 + tolerance && joystickY >= 1013 - tolerance && joystickY <= 1023 + tolerance) {
    Serial.println("Backward");
  }
  // Right
  else if (joystickX >= 1018 - tolerance && joystickX <= 1023 + tolerance && joystickY >= 515 - tolerance && joystickY <= 525 + tolerance) {
    Serial.println("Right");
  }
  // Left
  else if (joystickX >= -tolerance && joystickX <= 10 + tolerance && joystickY >= 515 - tolerance && joystickY <= 525 + tolerance) {
    Serial.println("Left");
  }
  // right turn
  else if (joystickX >= 1018 - tolerance && joystickX <= 1023 + tolerance && joystickY >= -tolerance && joystickY <= 10 + tolerance) {
    Serial.println("Right turn");
  }
  // left turn
  else if (joystickX >= -tolerance && joystickX <= 10 + tolerance && joystickY >= -tolerance && joystickY <= 10 + tolerance) {
    Serial.println("Left turn");
  }
  else {
    // X-Axis value
    Serial.print("X : ");
    Serial.print(joystickX);

    // Y-Axis value
    Serial.print(" Y : ");
    Serial.println(joystickY);
  }

  delay(100);
}
