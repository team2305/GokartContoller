#include <Servo.h>

Servo servoLeft;
Servo servoRight;
int posLeft = 0;
int posRight = 0;

const int relayDoor1 = 6;
const int relayDoor2 = 7;
const int inputDoor1 = 2;
const int inputDoor2 = 3;
const int inputMirror = 4;

int stateMirror = 0;
int stateDoor1 = 0;
int stateDoor2 = 0;
int top = 0;
int bottom = 0;
int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;

int limitTop = 10;
boolean limitTopLastState;
boolean limitTopState = HIGH ;

int limitBottom = 11;
boolean limitBottomLastState;
boolean limitBottomState = HIGH ;

void setup()
{
  pinMode(inputDoor1, INPUT);
  pinMode(inputDoor2, INPUT);
  pinMode(inputMirror, INPUT);
  pinMode(limitTop, INPUT);
  pinMode(limitBottom, INPUT);
  pinMode(relayDoor1, OUTPUT);
  pinMode(relayDoor2, OUTPUT);
  servoLeft.attach(8);
  servoRight.attach(9);
  Serial.begin(9600);
}
void loop() {
  stateMirror = digitalRead(inputMirror);
  stateDoor1 = digitalRead(inputDoor1);
  stateDoor2 = digitalRead(inputDoor2);
  top = digitalRead(limitTop);
  bottom = digitalRead(limitBottom);

  if (stateMirror < 2) {
    if (stateMirror == 0) {
      servoLeft.write(0);
      servoRight.write(0);
    }
    else if (stateMirror == 1) {
      servoLeft.write(170);
      servoRight.write(170);
    }
    //Serial.println(stateMirror);
  }

  if ( bottom == LOW && limitBottomLastState == HIGH ) {
    delay (10);
    if (digitalRead(limitBottom) == LOW)limitBottomState = !limitBottomState;
    if (check1 <= 0) check1++;
    else check1 = 0;
  }
  limitBottomLastState = bottom;


  if ( top == LOW && limitTopLastState == HIGH ) {
    delay (10);
    if (digitalRead(limitTop) == LOW)limitTopState = !limitTopState;
    if (check2 <= 0) check2++;
    else check2 = 0;
  }
  limitTopLastState = top;


  if ((check1 == 0) && (check2 == 0) && (check3 == 0) && (check4 == 0) && (stateDoor1 == 0)) {
    digitalWrite(relayDoor1, LOW);
    digitalWrite(relayDoor2, HIGH);
    check3 = 1;
  }
  if ((check1 == 1) && (check2 == 0) && (check3 == 1) && (check4 == 0) && (stateDoor1 == 0)) {
    digitalWrite(relayDoor1, HIGH);
    digitalWrite(relayDoor2, LOW);
    delay(200);
    digitalWrite(relayDoor1, HIGH);
    digitalWrite(relayDoor2, HIGH);
    check4 = 1;
  }
  if ((check1 == 1) && (check2 == 0) && (check3 == 1) && (check4 == 1) && (stateDoor1 == 1)) {
    digitalWrite(relayDoor1, HIGH);
    digitalWrite(relayDoor2, LOW);
    check3 = 0;
    check1 = 0;
  }
  if ((check1 == 0) && (check2 == 1) && (check3 == 0) && (check4 == 1) && (stateDoor1 == 1)) {
    digitalWrite(relayDoor1, LOW);
    digitalWrite(relayDoor2, HIGH);
    delay(200);
    digitalWrite(relayDoor1, HIGH);
    digitalWrite(relayDoor2, HIGH);
    check4 = 0;
    check2 = 0;
  }
  Serial.println(check1);
  Serial.println(check2);
  Serial.println(check3);
  Serial.println(check4);
  Serial.println(stateDoor1);
  Serial.println();
  delay(300);
}
/*if (check <= 1 ) {
   if ((stateDoor1 == 0) && (stateDoor2 == 1)) {
     if (top == 1) {
       digitalWrite(relayDoor1, LOW);
       digitalWrite(relayDoor2, HIGH);
     }
     else {
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, HIGH);

     }
     else if ((stateDoor1 == 1) && (stateDoor2 == 0)) {
       //if (!digitalRead(limitBottom)) {}
       //else {
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, LOW);
       delay(500);
       //}
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, HIGH);
     }
     else if ((stateDoor1 == 0) && (stateDoor2 == 0)) {
       digitalWrite(relayDoor1, LOW);
       digitalWrite(relayDoor2, HIGH);
       delay(500);
       //}
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, HIGH);
     }
     else if ((stateDoor1 == 1) && (stateDoor2 == 1)) {
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, LOW);
       delay(500);
       //}
       digitalWrite(relayDoor1, HIGH);
       digitalWrite(relayDoor2, HIGH);
     }
     Serial.println(top); Serial.println(bottom); Serial.println();
 } */
