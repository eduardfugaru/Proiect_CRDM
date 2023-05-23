const int MOTION_SENSOR_PIN = 2;   // Pin Arduino la output pin PIR
const int BUZZER_PIN        = 3;   // Pin Arduino la pin buzzer
int motionStateCurrent      = LOW; // Starea curenta a pinului senzorului PIR
int motionStatePrevious     = LOW; // Starea anterioara a pinului senzorului PIR

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // setare pin Arduino ca input
  pinMode(BUZZER_PIN, OUTPUT);          // setare pin Arduino ca output
}

void loop() {
  motionStatePrevious = motionStateCurrent;            // stocheaza starea anterioara
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // citeste starea noua

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // schimbare stare pin din LOW in HIGH
    Serial.println("Motion detected!");
    digitalWrite(BUZZER_PIN, HIGH); // porneste sunetul pe buzzer
  }
  else
  if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // schimbare stare pin din HIGH in LOW
    Serial.println("Motion stopped!");
    digitalWrite(BUZZER_PIN, LOW);  // se opreste sunetul pe buzzer
  }
}
