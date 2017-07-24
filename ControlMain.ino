int mirrorPin = 2;
int mirrorOut = 7;
boolean mirrorPinState;
boolean mirrorLastState;
boolean mirrorState = LOW ;

int doorPin = 3;
int doorOut1 = 8;
int doorOut2 = 9;
boolean doorPinState;
boolean doorLastState;
boolean doorState = LOW ;

int lightPin = 4;
int lightOut1 = 10;
int lightOut2 = 11;
boolean lightPinState;
boolean lightLastState;
boolean lightState = LOW ;

int mirrorCount = 0 ;
int doorCount = 0 ;
int lightCount = 0 ;



void setup() {
  pinMode (mirrorPin, INPUT);
  pinMode (mirrorOut, OUTPUT); //mirror
  pinMode (doorPin, INPUT);
  pinMode (doorOut1, OUTPUT);
  pinMode (doorOut2, OUTPUT); //door
  pinMode (lightPin, INPUT);
  pinMode (lightOut1, OUTPUT);
  pinMode (lightOut2, OUTPUT); //light
  Serial.begin(9600);

}

void loop() {
  int reading1 = digitalRead(mirrorPin);
  int reading2 = digitalRead(doorPin);
  int reading3 = digitalRead(lightPin);
  delay(100);


  // MIRROR
  if ( reading1 == LOW && mirrorLastState == HIGH ) {
    delay (10);
    if (digitalRead(mirrorPin) == LOW)mirrorState = !mirrorState;
    if (mirrorCount <= 0) mirrorCount += 1;
    else mirrorCount = 0;
  }
  digitalWrite(mirrorOut, mirrorState);
  mirrorLastState = reading1;

  // DOOR
  if ( reading2 == LOW && doorLastState == HIGH ) {
    delay (10);
    if (digitalRead(doorPin) == LOW) doorState = !doorState;
    if (doorCount <= 2) doorCount += 1;
    else doorCount = 0;
  }
  doorLastState = reading2;

  if (doorCount == 1 ) {
    digitalWrite(doorOut1, LOW);
    digitalWrite(doorOut2, HIGH);
  }
  else if (doorCount == 2 ) {
    digitalWrite(doorOut1, HIGH);
    digitalWrite(doorOut2, LOW);
  }
  else if (doorCount == 3 ) {
    digitalWrite(doorOut1, HIGH);
    digitalWrite(doorOut2, HIGH);
  }
  else {
    digitalWrite(doorOut1, LOW);
    digitalWrite(doorOut2, LOW);
  }

  // LIGHT
  if ( reading3 == LOW && lightLastState == HIGH ) {
    delay (10);
    if (digitalRead(lightPin) == LOW) lightState = !lightState;
    if (lightCount <= 2) lightCount += 1;
    else lightCount = 0;
  }
  lightLastState = reading3;

  if (lightCount == 1 ) {
    digitalWrite(lightOut1, LOW);
    digitalWrite(lightOut2, HIGH);
  }
  else if (lightCount == 2 ) {
    digitalWrite(lightOut1, HIGH);
    digitalWrite(lightOut2, LOW);
  }
  else if (lightCount == 3 ) {
    digitalWrite(lightOut1, HIGH);
    digitalWrite(lightOut2, HIGH);
  }
  else {
    digitalWrite(lightOut1, LOW);
    digitalWrite(lightOut2, LOW);
  }

  Serial.println( mirrorState );
  Serial.println(doorCount);
  Serial.println(lightCount);
  Serial.println();


}

