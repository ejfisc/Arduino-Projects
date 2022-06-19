int greenLED = 12;
int yellowLED = 11;
int redLED = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //go Mode
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.println("Light Mode: GO");
  delay(2000);

  //yield mode
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  Serial.println("Light Mode: Yield");
  delay(2000);

  //stop mode
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  Serial.println("Light Mode: STOP");
  delay(2000);
}
