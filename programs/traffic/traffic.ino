// Traffic Light Control Arduino Code

const int redPin = 2;    // Red LED connected to digital pin 2
const int yellowPin = 3; // Yellow LED connected to digital pin 3
const int greenPin = 4;  // Green LED connected to digital pin 4

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Red light
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(5000); // Red light stays on for 5 seconds

  // Red and yellow lights (transition)
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000); // Red and yellow lights stay on for 2 seconds

  // Green light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(5000); // Green light stays on for 5 seconds

  // Yellow light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000); // Yellow light stays on for 2 seconds
}
