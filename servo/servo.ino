#include <Servo.h>

// Define the pin for the servo motor
int servoPin = 9;

// Define the pin for the soil moisture sensor
int moistureSensorPin = A0;

// Threshold value for moisture level indicating dry soil
int dryThreshold = 400;  // Adjust this value based on your sensor reading

Servo myservo;

void setup() {
  // Initialize the servo motor
  myservo.attach(servoPin);

  // Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture level
  int moistureLevel = analogRead(moistureSensorPin);

  // Print the moisture level for debugging
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Check the moisture level and control the servo motor
  if (moistureLevel > dryThreshold) {
    // If soil is dry, rotate the servo continuously
    rotateServoContinuously();
    Serial.println("Soil is dry. Rotating the servo.");
  } else {
    // Soil moisture level is sufficient, keep the servo at a neutral position
    myservo.write(90);
    Serial.println("Soil moisture is sufficient. Servo in neutral position.");
  }

  // Add a delay to prevent rapid changes
  delay(1000);  // Adjust the delay based on your requirements
}

void rotateServoContinuously() {
  // Rotate the servo continuously in one direction
  for (int angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    delay(15); // Adjust the delay based on your servo's speed
  }

  // Optional: Pause for a moment at the end of the rotation
  delay(1000);

  // Rotate the servo continuously in the opposite direction
  for (int angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    delay(15); // Adjust the delay based on your servo's speed
  }

  // Optional: Pause for a moment at the end of the rotation
  delay(1000);
}
