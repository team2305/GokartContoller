#include <UTFT.h>
#include <avr/pgmspace.h>

int mirror = 8;
int door1 = 9;
int door2 = 10;
int light1 = 11;
int light2 = 12;

int count1 = 0;
int count2 = 0;
int count3 = 0;

int i ;

int delayLetter = 200;
int cycleBring = 10 ;

UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

extern unsigned int batman2[0xD48];
extern unsigned int batman[0x27A6] ;
extern unsigned int rabbit[0x2D00] ;

void setup() {
  pinMode (mirror, INPUT);
  pinMode (door1, INPUT);
  pinMode (door2, INPUT);
  pinMode (light1, INPUT);
  pinMode (light2, INPUT);

  Serial.begin(9600);

  myGLCD.InitLCD();
  myGLCD.fillScr(255, 255, 255);
  myGLCD.drawBitmap (0, 48, 160, 72, rabbit, 2);
  delay(3000);
  myGLCD.fillScr(0, 0, 0);
  myGLCD.drawBitmap (15, 50, 145, 70, batman, 2);
  delay(3000);

  myGLCD.setFont(SmallFont);
  myGLCD.fillScr(255, 255, 255);
  myGLCD.drawBitmap (85, 160, 160, 72, rabbit, 1);


  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect (0, 0, 319, 152);
  myGLCD.drawRoundRect (0, 0, 319, 152);
  myGLCD.drawLine(0, 0, 319, 0);
  myGLCD.drawLine(0, 1, 319, 1);
  myGLCD.setColor(255, 255, 0);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.print("BAT MOBILE", CENTER, 8);
  myGLCD.setFont(SmallFont);
  myGLCD.print("RABBIT PROTOTYPE", CENTER, 26);
  myGLCD.setColor(47, 79, 79);
  myGLCD.fillRoundRect (3, 96, 316, 149);
  myGLCD.drawBitmap (120, 45, 85, 40, batman2, 1);

  myGLCD.setColor(104, 104, 104);
  myGLCD.drawRoundRect (2, 1, 60, 40);
  myGLCD.drawRoundRect (258, 1, 317, 40);
  myGLCD.drawRoundRect (2, 40, 50, 80);
  myGLCD.drawRoundRect (268, 40, 317, 80);

  myGLCD.setColor(80, 173, 226);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.print("LIGHT", 4, 82);
  myGLCD.print("LIGHT", 278, 82);

  myGLCD.setColor(118, 215, 196);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(47, 79, 79);
  myGLCD.print("W E L C O M E", CENTER, 115);
  delay(1000);

  for (i = 0; i <= 5; i++) {
    myGLCD.setColor(47, 79, 79);
    myGLCD.fillRoundRect (3, 96, 316, 149);
    delay(300);
    myGLCD.setColor(118, 215, 196);
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(47, 79, 79);
    myGLCD.print("W E L C O M E", CENTER, 115);
    delay(300);

  }
  myGLCD.setColor(47, 79, 79);
  myGLCD.fillRoundRect (3, 96, 316, 149);


}

void loop() {
  int mirrorRead = digitalRead(mirror);
  int door1Read = digitalRead(door1);
  int door2Read = digitalRead(door2);
  int light1Read = digitalRead(light1);
  int light2Read = digitalRead(light2);

  //Light OFF
  if (light1Read == 0 && light2Read == 0 && count1 == 0) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (240, 81, 319, 95);

    myGLCD.setColor(80, 173, 226);
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.print("OFF", 295, 82);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (3, 2, 59, 39);
    myGLCD.fillRoundRect (259, 2, 316, 39);
    myGLCD.fillRoundRect (3, 41, 49, 79);
    myGLCD.fillRoundRect (269, 41, 316, 79);
    count1 = 1;
  }

  //Light LEVEL1
  else if (light1Read == 0 && light2Read == 1 && count1 == 1) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (240, 81, 319, 95);

    myGLCD.setColor(80, 173, 226);
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.print("LEVEL1", 270, 82);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (3, 2, 59, 39);
    myGLCD.fillRoundRect (259, 2, 316, 39);
    myGLCD.setColor(0, 204, 255);
    myGLCD.fillRoundRect (3, 41, 49, 79);
    myGLCD.fillRoundRect (269, 41, 316, 79);
    count1 = 2;
  }

  //Light LEVEL2
  else if (light1Read == 1 && light2Read == 0 && count1 == 2) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (240, 81, 319, 95);

    myGLCD.setColor(80, 173, 226);
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.print("LEVEL2", 270, 82);

    myGLCD.setColor(0, 255, 255);
    myGLCD.fillRoundRect (3, 2, 59, 39);
    myGLCD.fillRoundRect (259, 2, 316, 39);
    myGLCD.setColor(0, 204, 255);
    myGLCD.fillRoundRect (3, 41, 49, 79);
    myGLCD.fillRoundRect (269, 41, 316, 79);
    count1 = 3;
  }

  //Flash Light
  else if (light1Read == 1 && light2Read == 1 && count1 == 3) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect (240, 81, 319, 95);

    myGLCD.setColor(80, 173, 226);
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.print("FLASH", 278, 82);
    for (i = 0; i <= cycleBring; i++) {
      myGLCD.setColor(0, 255, 255);
      myGLCD.fillRoundRect (3, 2, 59, 39);
      myGLCD.fillRoundRect (259, 2, 316, 39);
      myGLCD.setColor(0, 204, 255);
      myGLCD.fillRoundRect (3, 41, 49, 79);
      myGLCD.fillRoundRect (269, 41, 316, 79);
      delay(70);
      myGLCD.setColor(0, 0, 0);
      myGLCD.fillRoundRect (3, 2, 59, 39);
      myGLCD.fillRoundRect (259, 2, 316, 39);
      delay(70);
      myGLCD.setColor(0, 0, 0);
      myGLCD.fillRoundRect (3, 41, 49, 79);
      myGLCD.fillRoundRect (269, 41, 316, 79);
      delay(70);
      myGLCD.setColor(0, 204, 255);
      myGLCD.fillRoundRect (3, 41, 49, 79);
      myGLCD.fillRoundRect (269, 41, 316, 79);
      delay(100);
      myGLCD.setColor(0, 255, 255);
      myGLCD.fillRoundRect (3, 2, 59, 39);
      myGLCD.fillRoundRect (259, 2, 316, 39);
      delay(70);
    }
    count1 = 0;
  }


  //Door OPEN
  if (door2Read == 1 && count2 == 0) {
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(47, 79, 79);
    for (i = 0; i <= cycleBring; i++) {
      myGLCD.setColor(118, 215, 196);
      myGLCD.print("DOOR", CENTER, 105);
      myGLCD.print("OPEN", CENTER, 125);
      delay(delayLetter);
      myGLCD.setColor(250, 250, 250);
      myGLCD.print("DOOR", CENTER, 105);
      myGLCD.print("OPEN", CENTER, 125);
      delay(delayLetter);
    }
    delay(200);
    myGLCD.setColor(47, 79, 79);
    myGLCD.fillRoundRect (3, 96, 316, 149);
    count2 = 1;
  }
  //Door CLOSE
  else if (door2Read == 0 && count2 == 1) {
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(47, 79, 79);
    for (i = 0; i <= cycleBring; i++) {
      myGLCD.setColor(118, 215, 196);
      myGLCD.print("DOOR", CENTER, 105);
      myGLCD.print("CLOSE", CENTER, 125);
      delay(delayLetter);
      myGLCD.setColor(250, 250, 250);
      myGLCD.print("DOOR", CENTER, 105);
      myGLCD.print("CLOSE", CENTER, 125);
      delay(delayLetter);
    }
    delay(200);
    myGLCD.setColor(47, 79, 79);
    myGLCD.fillRoundRect (3, 96, 316, 149);
    count2 = 0;
  }


  //Mirror DOWN
  if (mirrorRead == 0 && count3 == 0) {
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(47, 79, 79);
    for (i = 0; i <= cycleBring; i++) {
      myGLCD.setColor(118, 215, 196);
      myGLCD.print("UnArmed", CENTER, 115);
      delay(200);
      myGLCD.setColor(250, 250, 250);
      myGLCD.print("UnArmed", CENTER, 115);
      delay(200);
    }
    myGLCD.setColor(47, 79, 79);
    myGLCD.fillRoundRect (3, 96, 316, 149);
    count3 = 1;
  }

  //Mirror UP
  else if (mirrorRead == 1 && count3 == 1) {
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(47, 79, 79);
    for (i = 0; i <= cycleBring; i++) {
      myGLCD.setColor(118, 215, 196);
      myGLCD.print("Armed", CENTER, 115);
      delay(200);
      myGLCD.setColor(250, 250, 250);
      myGLCD.print("Armed", CENTER, 115);
      delay(200);
    }
    myGLCD.setColor(47, 79, 79);
    myGLCD.fillRoundRect (3, 96, 316, 149);
    count3 = 0;
  }

}
