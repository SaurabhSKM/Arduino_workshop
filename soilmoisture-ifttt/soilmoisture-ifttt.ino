

  #include <ESP8266WiFi.h>

// Replace with your Wi-Fi credentials
const char* ssid = "Redmi 10 Power";
const char* password = "avadakedavra";

// Replace with your IFTTT Webhooks API key and event name
const char* apiKey = "R7MWN8JTI8FEJZPD";
const char* eventName = "soil_moisture";

// Replace with your soil moisture sensor pin
const int soilMoisturePin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Read soil moisture level
  int soilMoisture = analogRead(soilMoisturePin);

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  // Replace the condition with your desired moisture level threshold
  if (soilMoisture < 500) {
    // Trigger IFTTT to send an email
    triggerIFTTTEmail(soilMoisture);
    delay(60000); // Wait for a minute to avoid repeated triggers
  }

  delay(1000); // Delay between readings
}

void triggerIFTTTEmail(int value) {
  WiFiClient client;

  
 String url = "/trigger/soil_moisture/json/with/key/ppOwjnj2mmgSMq8ghUOK9onCC8o81TWKPNJOMg4tg0C?value1=" + String(value);


  Serial.println("Sending HTTP request to IFTTT...");

  if (client.connect("maker.ifttt.com", 80)) {
    // Make an HTTP request
    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();

    // Wait for the response
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }

    // Close the connection
    client.stop();
  } else {
    Serial.println("Unable to connect to IFTTT");
  }
}
