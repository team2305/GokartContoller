const int state1 = 10;
const int state2 = 11;
const int fLED = 3;

int i;
int stateLED1 = 0;
int stateLED2 = 0;
int fBright = 200;
int indexLED = 70;

void setup()
{
  pinMode(state1, INPUT);
  pinMode(state2, INPUT);
  pinMode(fLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  stateLED1 = digitalRead(state1);
  stateLED2 = digitalRead(state2);
  Serial.println(stateLED1);
  Serial.println(stateLED2);
  Serial.println();
  if ((stateLED1 == 0) && (stateLED2 == 1)) {
    analogWrite(fLED, 50);
  }
  else if ((stateLED1 == 1) && (stateLED2 == 0)) {
    analogWrite(fLED, fBright);
  }
  else if ((stateLED1 == 1) && (stateLED2 == 1)) {
  analogWrite(fLED, 10); delay(1000);
    for (i = 0; i <= 10; i++) {
      analogWrite(fLED, fBright);
      delay(indexLED);
      analogWrite(fLED, 0);
      delay(indexLED);
      fBright+=5;
    }
    fBright=200;
  }
  else {
    analogWrite(fLED, 0);
  }
}
