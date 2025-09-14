#include <Servo.h>

const int irSensorPin = 2;   // IR sensor connected to digital pin 2
const int servoPin = 9;      // Servo motor signal pin

Servo myServo;               // Create servo object

void setup() {
  pinMode(irSensorPin, INPUT);    // IR sensor as input
  myServo.attach(servoPin);       // Attach servo motor
  myServo.write(0);               // Start with servo at 0°
  Serial.begin(9600);             // Serial monitor (optional)
}

void loop() {
  int irValue = digitalRead(irSensorPin);  // Read IR sensor

  if (irValue == LOW) {   // LOW = Object detected
    Serial.println("Object Detected - Servo ON");
    myServo.write(90);    // Servo moves to 90°
  } else {
    Serial.println("No Object - Servo OFF");
    myServo.write(0);     // Servo goes back to 0°
  }

  delay(200);  // Small delay to avoid flickering
}
