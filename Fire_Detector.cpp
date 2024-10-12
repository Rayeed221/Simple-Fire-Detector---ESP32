#include <Arduino.h>

int smoke_detector = 34;
int flame_detector = 35;
int buzzer = 14;
int switchPin = 12; 

bool flame_b = false;
bool smoke_b = false;
bool buzzerSwitch = false;

void setup() {
  Serial.begin(9600);
  pinMode(flame_detector, INPUT);
  pinMode(smoke_detector, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); 

}

void loop() {
  int flame = digitalRead(flame_detector);
  int smoke = analogRead(smoke_detector);
 Serial.println(flame);
  if (digitalRead(switchPin) == 0) {
    buzzerSwitch = true;
    Serial.println(digitalRead(switchPin));

    }

  if (buzzerSwitch == true) {
    digitalWrite(buzzer, LOW);  
    flame_b = false;
    smoke_b = false;
    buzzerSwitch = false;
 }
  if (flame == 0 && smoke >= 3000) {
    flame_b = true;
    smoke_b = true;
  } if (smoke >= 3000) {
    smoke_b = true;
  }
  
  if (flame_b == true && smoke_b == true) {
    Serial.println("Fire and Smoke");
    digitalWrite(buzzer, HIGH);
    delay(100);
   
   
  } if (smoke_b == true  && flame_b == false) {
    Serial.println("Smoke");

    for(int i=1; i<256; i++){
        analogWrite(buzzer, i);
        delay(5);
    }
    for(int i=255; i>0; i--){
        analogWrite(buzzer, i);
        delay(5);
  }}
 
}