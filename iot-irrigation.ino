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
}

void loop() {
  // read the state of the the input pin:
  
  touch_state = digitalRead(SENSOR_PIN);
  if(touch_state == HIGH && flag==0) {
    Serial.println("Motor switched on");
    flag=1;
    digitalWrite(MOTOR_PIN, HIGH); 
    delay(1000);
  }
  if(digitalRead(SENSOR_PIN)==HIGH && flag==1) {
    digitalWrite(MOTOR_PIN, LOW); 
    flag=0;
    Serial.println("Motor switched off");
    delay(1000);
  }
}
