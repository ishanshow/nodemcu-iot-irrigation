const int SENSOR_PIN = 13;
const int MOTOR_PIN = 4;
int prev_state = LOW;  // The previous state from the input pin
int touch_state;     // The current reading from the input pin
int flag=0;

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(115200);
  // initialize the ESP8266 NodeMCU's pin as an input
  pinMode(SENSOR_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT); 
 // digitalWrite(MOTOR_PIN, LOW);
}

void loop() {
  // read the state of the the input pin:
  
  touch_state = digitalRead(SENSOR_PIN);
  if(prev_state == LOW && touch_state == HIGH) {
    Serial.println("The sensor is touched");
    digitalWrite(MOTOR_PIN, HIGH); 
      }
  else if(prev_state == HIGH && touch_state == LOW) {
    Serial.println("The sensor is released");
    digitalWrite(MOTOR_PIN, LOW);
  }

  // save the the last state
  prev_state = touch_state;
}
