const int SENSOR_PIN = 13;
const int MOTOR_PIN = 4;
int prev_state = LOW;  // The previous state from the input pin
int touch_state;     // The current reading from the input pin
int is_on=0;

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);
  // initialize the ESP8266 NodeMCU's pin as an input
  pinMode(SENSOR_PIN, INPUT);
  // initialize the Motor's pin as an output
  pinMode(MOTOR_PIN, OUTPUT); 
}

void loop() {
  // read the state of the the input pin:
  
  touch_state = digitalRead(SENSOR_PIN);
  if(touch_state == HIGH && is_on==0) {
    digitalWrite(MOTOR_PIN, HIGH); 
    is_on=1;
    Serial.println("Motor switched on");
    delay(1000);
  }
  if(digitalRead(SENSOR_PIN)==HIGH && is_on==1) {
    digitalWrite(MOTOR_PIN, LOW); 
    is_on=0;
    Serial.println("Motor switched off");
    delay(1000);
  }
}
