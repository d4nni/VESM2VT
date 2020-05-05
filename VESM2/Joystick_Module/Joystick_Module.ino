int xPin = A1;
int yPin = A0;
int ledPin1 = 1;
int ledPin2= 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;
int ledPin6 = 6;
int ledPin7 = 7;
int ledPin8 = 8;

int xPosition = 0;
int yPosition = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  //activate pull-up resistor on the push-button pin 
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);

  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  if ((xPosition == 506) && (yPosition == 516)){
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
  if(xPosition == 0 && (yPosition == 516)){
    if (ledPin1 == HIGH){
      digitalWrite(ledPin1, HIGH);
    } else if (ledPin2 == HIGH){
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    } else if (ledPin3 == HIGH){
      digitalWrite(ledPin2,HIGH);
      digitalWrite(ledPin3, LOW);
    } else if (ledPin4 == HIGH){
      digitalWrite(ledPin3,HIGH); 
      digitalWrite(ledPin4, LOW);
    }
  } 
  if(xPosition == 1023 && (yPosition == 517)){
    if (ledPin1 == HIGH){
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin1, LOW);
    } else if (ledPin2 == HIGH){
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin2, LOW);
    } else if (ledPin3 == HIGH){
      digitalWrite(ledPin4,HIGH);
      digitalWrite(ledPin3, LOW);
    } else if (ledPin4 == HIGH){
      digitalWrite(ledPin4,HIGH); 
    }
  }
      
  delay(1000);
}
