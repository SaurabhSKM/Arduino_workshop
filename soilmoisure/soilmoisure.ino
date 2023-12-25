// Capacitive Soil Moisture Sensor Arduino Code

const int soilMoisturePin = A0; // Analog pin connected to the soil moisture sensor

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

  delay(1000); // Delay for readability and to avoid rapid changes
}


