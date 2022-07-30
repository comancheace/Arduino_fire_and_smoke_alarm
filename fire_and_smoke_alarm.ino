#define MQ2pin 0 // KY-026 analog interface
#define digitalPin 2 // KY-026 digital interface
int digitalVal; // digital readings
int Buzzer = 10; // Connect buzzer pin to 10

float sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Gas sensor warming up!");
  delay(20000); // allow the MQ-6 to warm up
  pinMode(digitalPin, INPUT);
  pinMode(digitalPin, INPUT_PULLUP);
}

void loop() {

  // Read the digital pin
  digitalVal = digitalRead(digitalPin);
  if (digitalVal == HIGH) // if flame is detected then
  {
    Serial.print(" | Fire detected!");
    tone(Buzzer,2000);
    delay(500);
    tone(Buzzer,4000);
    delay(500);
  }
  else
  {
    Serial.println(" | No fire detected!");
    noTone(Buzzer);
  }
  
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  if(sensorValue > 80)
  {
    Serial.print(" | Smoke detected!");
    tone(Buzzer,1000);
    delay(500);
    tone(Buzzer,2000);
    delay(500);
  }
  else
  {
    Serial.println(" | No smoke detected!");
    noTone(Buzzer);  
  }
  
  Serial.println("");
  delay(1000); // wait 2s for next reading

  

}
