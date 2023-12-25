#include <Stepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 200;

// Create an instance of the Stepper class
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Define the pin for the soil moisture sensor
int moistureSensorPin = A0;

// Threshold value for moisture level indicating dry soil
int dryThreshold = 500;  // Adjust this value based on your sensor reading

void setup() {
  // Set the speed of the stepper motor
  myStepper.setSpeed(100);

  // Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture level
  int moistureLevel = analogRead(moistureSensorPin);

  // Print the moisture level for debugging
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Check the moisture level and control the stepper motor
  if (moistureLevel > dryThreshold) {
    // If soil is dry, move the stepper motor
    moveStepperMotor();
    Serial.println("Soil is dry. Moving the stepper motor.");
  } else {
    Serial.println("Soil moisture is sufficient. Stepper motor is stationary.");
  }

  // Add a delay to prevent rapid changes
  delay(1000);  // Adjust the delay based on your requirements
}

void moveStepperMotor() {
  // Move the stepper motor one full revolution
  myStepper.step(stepsPerRevolution);

  // Optional: Pause for a moment after the movement
  delay(1000);
}
