#include <Arduino.h>

static const int LED_GREEN = 16;
static const int LED_BLUE = 5; //D1
static const int LED_RED = 4; //D2
static const int SWITCH_1 = 0; // D3
static const int SWITCH_GROUND_3 = 12; //D6
static const int SWITCH_GROUND_4 = 14; //D5

int dimm[4][4];
bool sg[4][4];



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(SWITCH_1, INPUT_PULLUP);

  pinMode(SWITCH_GROUND_3, OUTPUT);
  pinMode(SWITCH_GROUND_4, OUTPUT);
  
  digitalWrite(SWITCH_GROUND_3, HIGH); //[0][2] --> IF LOW
  digitalWrite(SWITCH_GROUND_4, HIGH);  //[0][3] --> IF LOW


}

void loop() {
  // put your main code here, to run repeatedly:
 /*  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(1000);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  delay(1000); */
  digitalWrite(SWITCH_GROUND_3, LOW);
  digitalWrite(SWITCH_GROUND_4, HIGH);

  sg[0][2] = !digitalRead(SWITCH_1);
  
  analogWrite(LED_BLUE, dimm[0][2]);
  if (sg[0][2]) {
    dimm[0][2] = 1024; 
  }
  if (dimm[0][2] > 0) {
    dimm[0][2]--;
    delayMicroseconds(100);

  }
  
  digitalWrite(SWITCH_GROUND_3, HIGH);
  digitalWrite(SWITCH_GROUND_4, LOW);

  sg[0][3] = !digitalRead(SWITCH_1);

  analogWrite(LED_RED, dimm[0][3]);
  if (sg[0][3]) {
    dimm[0][3] = 1024; 
  }
  if (dimm[0][3] > 0) {
    dimm[0][3]--;
    delayMicroseconds(100);

  }

}