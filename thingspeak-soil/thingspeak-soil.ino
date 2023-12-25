#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Replace these values with your ThingSpeak channel details
String apiKey = "R7MWN8JTI8FEJZPD";

// Analog pin connected to a sensor
int sensorPin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin("Redmi 10 Power", "avadakedavra"); // Replace with your WiFi credentials

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // read the value from the sensor:
  int sensorValue = analogRead(sensorPin);
  
  // print the sensor value to the serial monitor:
  Serial.println(sensorValue);

  // construct the URL for ThingSpeak
  String url = "http://api.thingspeak.com/update?api_key=" + apiKey + "&field1=" + String(sensorValue);

  // make a HTTP request:
  WiFiClient client;
  HTTPClient http;
  http.begin(client, url);

  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
    Serial.println("Failed to send data to ThingSpeak");
  }

  http.end();

  // ThingSpeak has a 15-second delay between updates, so we wait:
  delay(15000);
}
