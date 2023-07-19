
#include <Keyboard.h>

#define flexPin1 A1
#define flexPin2 A2
int Lefthandsecond = A3;
int Righthandsecond = A4;
int Lefthandthird = A5;
int Righthandthird = A6;
int Bottom = A7;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

int buttonCount1 = 0;
int buttonCount2 = 0;
int buttonCount3 = 0;
int buttonCount4 = 0;
int buttonCount5 = 0;

unsigned long pressTime1 = 0;
unsigned long pressTime2 = 0;

int mainPrinted = 0;
int restartPrinted = 0;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  int flexValue1;
  int flexValue2;
  int LeftMove = analogRead(Lefthandsecond);
  int RightMove = analogRead(Righthandsecond);
  int Watchturn = analogRead(Lefthandthird);
  int WatchReverceturn = analogRead(Righthandthird);
  int Hold = analogRead(Bottom);

  flexValue1 = analogRead(flexPin1);
  flexValue2 = analogRead(flexPin2);

  Serial.print("flex sensor 1 = ");
  Serial.println(flexValue1);

  Serial.print("flex sensor 2 = ");
  Serial.println(flexValue2);

  if (flexValue1 < 20 && flexValue2 < 20) {
    Serial.print("hard drop\n");
    Keyboard.press(' ');
    while (flexValue1 < 20 && flexValue2 < 20) {
      flexValue1 = analogRead(flexPin1);
      flexValue2 = analogRead(flexPin2);
    }
    Keyboard.release(' ');
  } else if (flexValue1 < 20) {
    Serial.print("down\n");
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.release(KEY_DOWN_ARROW);
  } else if (flexValue2 < 20) {
    Serial.print("down\n");
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.release(KEY_DOWN_ARROW);
  }

  if (LeftMove > 10 && buttonState1 == 0) {
    buttonState1 = 1;
    buttonCount1++;
    Serial.print("LeftMove ");
    Serial.println(buttonCount1);
    pressTime1 = millis();
    mainPrinted = 0;
    Keyboard.press(KEY_LEFT_ARROW);
  } else if (LeftMove <= 10 && buttonState1 == 1) {
    buttonState1 = 0;
    pressTime1 = 0;
    mainPrinted = 0;
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if (RightMove > 10 && buttonState2 == 0) {
    buttonState2 = 1;
    buttonCount2++;
    Serial.print("RightMove ");
    Serial.println(buttonCount2);
    pressTime2 = millis();
    restartPrinted = 0;
    Keyboard.press(KEY_RIGHT_ARROW);
  } else if (RightMove <= 10 && buttonState2 == 1) {
    buttonState2 = 0;
    pressTime2 = 0;
    restartPrinted = 0;
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  if (Watchturn > 10 && buttonState3 == 0) {
    buttonState3 = 1;
    buttonCount3++;
    Serial.print("Watchturn ");
    Serial.println(buttonCount3);
    Keyboard.press(KEY_UP_ARROW);
  } else if (Watchturn <= 10 && buttonState3 == 1) {
    buttonState3 = 0;
    Keyboard.release(KEY_UP_ARROW);
  }

  if (WatchReverceturn > 10 && buttonState4 == 0) {
    buttonState4 = 1;
    buttonCount4++;
    Serial.print("WatchReverceturn ");
    Serial.println(buttonCount4);
    Keyboard.press('z');
  } else if (WatchReverceturn <= 10 && buttonState4 == 1) {
    buttonState4 = 0;
    Keyboard.release('z');
  }

  if (Hold > 10 && buttonState5 == 0) {
    buttonState5 = 1;
    buttonCount5++;
    Serial.print("Hold ");
    Serial.println(buttonCount5);
    Keyboard.press('x');
  } else if (Hold <= 10 && buttonState5 == 1) {
    buttonState5 = 0;
    Keyboard.release('x');
  }

  if (pressTime1 > 0 && millis() - pressTime1 >= 3000 && Watchturn > 10 && !mainPrinted) {
    pressTime1 = millis();
    Serial.println("Main");
    mainPrinted = 1;
    Keyboard.press('m');
    delay(100);
    Keyboard.release('m');
  }

  if (pressTime2 > 0 && millis() - pressTime2 >= 3000 && WatchReverceturn > 10 && !restartPrinted) {
    pressTime2 = millis();
    Serial.println("Restart");
    restartPrinted = 1;
    Keyboard.press('r');
    delay(100);
    Keyboard.release('r');
  }

  delay(100);
}
