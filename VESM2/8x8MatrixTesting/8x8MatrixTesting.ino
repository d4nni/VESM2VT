const int ledPin1 = 12;
const int ledPin16 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, INPUT);
  pinMode(ledPin16, INPUT);
}

void loop() {
  digitalRead(ledPin1);
  digitalRead(ledPin16);
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin16, HIGH);
}
