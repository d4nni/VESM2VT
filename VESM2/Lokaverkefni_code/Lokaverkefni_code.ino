//hafa servo með
#include <Servo.h>

// definea alla pinna
#define SERVO_PINNI_1 3
#define SERVO_PINNI_2 4

#define MOTOR1_EN 5
#define MOTOR1_IN1 6
#define MOTOR1_IN2 7

#define MOTOR2_EN 10
#define MOTOR2_IN3 9
#define MOTOR2_IN4 8

const int pingPinni = 12;

Servo servoMotor1;
Servo servoMotor2;

// setup stillir alla pinna á sína stöður
void setup() {
  Serial.begin(9600);
  servoMotor1.attach(SERVO_PINNI_1);
  servoMotor2.attach(SERVO_PINNI_2);
  
  pinMode(MOTOR1_EN, OUTPUT);
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_EN, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
  
  Serial.println("Sláðu inn h eða v, a eða b, r eða s");
}

// loopan prentar út fjarlægð bílsins frá hlut
void loop() {
  	long duration, cm;
  
  	pinMode(pingPinni, OUTPUT);
    digitalWrite(pingPinni, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPinni, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPinni, LOW);	
  
  	pinMode(pingPinni, INPUT);
  	duration = pulseIn(pingPinni, HIGH);
  
  	cm = microsecondsToCentimeters(duration);
  
  	Serial.print("Fjarlægð: ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  // loopan tekur líka inn bókstaf sem stjórnar hvernig bíllinn hreyfir sig
  if(cm > 50){
      char ch = Serial.read();
    //h er fyrir hægri
      if(String(ch) == "h") {
          servoMotor1.write(45);
          servoMotor2.write(45);
    // v fyrir vinstri
      }else if(String(ch) == "v") {
          servoMotor1.write(135);
          servoMotor2.write(135);
    // a fyrir áfram
      }else if(String(ch) == "a") {
          digitalWrite(MOTOR1_IN1, LOW);
          digitalWrite(MOTOR1_IN2, HIGH);
          digitalWrite(MOTOR1_EN, 255);

          digitalWrite(MOTOR2_IN3, HIGH);
          digitalWrite(MOTOR2_IN4, LOW);
          digitalWrite(MOTOR2_EN, 255);
    // b fyrir bakka
      }else if(String(ch) == "b") {
          digitalWrite(MOTOR1_IN1, HIGH);
          digitalWrite(MOTOR1_IN2, LOW);
          digitalWrite(MOTOR1_EN, 255);

          digitalWrite(MOTOR2_IN3, LOW);
          digitalWrite(MOTOR2_IN4, HIGH);
          digitalWrite(MOTOR2_EN, 255);
    // r til að rétta bílinn af
      }else if(String(ch) == "r") {
          servoMotor1.write(93);
          servoMotor2.write(93);
    // s til að stöðva bílinn
      }else if(String(ch) == "s") {
          digitalWrite(MOTOR1_IN1, HIGH);
          digitalWrite(MOTOR1_IN2, HIGH);
          digitalWrite(MOTOR1_EN, 0);

          digitalWrite(MOTOR2_IN3, HIGH);
          digitalWrite(MOTOR2_IN4, HIGH);
          digitalWrite(MOTOR2_EN, 0);
      }
  // ef að bíllinn fer nær einhverju en 50 cm stöðvar hann
  }else if(cm < 50) {
		digitalWrite(MOTOR1_IN1, HIGH);
        digitalWrite(MOTOR1_IN2, HIGH);
        digitalWrite(MOTOR1_EN, 0);

        digitalWrite(MOTOR2_IN3, HIGH);
        digitalWrite(MOTOR2_IN4, HIGH);
        digitalWrite(MOTOR2_EN, 0);
	}
}

// jafna til að reikna út cm
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
