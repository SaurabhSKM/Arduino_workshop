#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11

const char* ssid = "Sujithra";
const char* password = "nithilan1";

const char* iftttEvent = "Humidity";
const char* iftttKey = "bI1-VH9Jy8Ucn6fhEZ3LUD";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%");

  // Send humidity data to IFTTT
  sendHumidityToIFTTT(humidity);
}

void sendHumidityToIFTTT(float humidity) {
  WiFiClient client;
  const char* host = "maker.ifttt.com";
  String url = "/trigger/Humidity/json/with/key/bI1-VH9Jy8Ucn6fhEZ3LUD?value1=" + String(humidity);


  if (client.connect(host, 80)) {
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" +"Connection: close\r\n\r\n");
    delay(10);
    client.stop();
  }
}


