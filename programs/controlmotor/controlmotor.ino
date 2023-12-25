#include <Stepper.h>

// Define the number of steps per revolution for your stepper motor
const int stepsPerRevolution = 200;

// Initialize the stepper motor with the sequence of control pins
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

// Analog pin connected to the soil moisture sensor
const int soilMoisturePin = A0;

// Moisture threshold to activate the stepper motor (adjust as needed)
const int moistureThreshold = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Map the sensor value to a range (adjust these values based on your sensor)
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Print the moisture percentage to the serial monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Check if the soil moisture is below the threshold to activate the stepper motor
  if (moisturePercentage < moistureThreshold) {
    // Rotate the stepper motor (adjust the number of steps and speed as needed)
    stepper.setSpeed(100);  // Set the speed in RPM
    stepper.step(stepsPerRevolution);
    delay(1000); // Delay to observe motor movement

    // Add any additional actions you want to perform when the soil is dry
  }

  delay(5000); // Delay between moisture readings (adjust as needed)
}
