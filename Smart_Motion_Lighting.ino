int pirPin = 2;
int ldrPin = A0;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.println("Smart Motion Light System Ready...");
}

void loop() {
  int motion = digitalRead(pirPin);
  int ldrValue = analogRead(ldrPin);
  int brightness = map(ldrValue, 0, 1023, 0, 100);

  if (motion == HIGH && brightness < 40) {
    if (brightness < 15) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }
    else {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
    }
    Serial.print("Motion Detected | Light: ");
    Serial.print(brightness);
    Serial.println("%");
    delay(10000);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    Serial.print("No Motion | Light: ");
    Serial.print(brightness);
    Serial.println("%");
    delay(1000);
  }
}

