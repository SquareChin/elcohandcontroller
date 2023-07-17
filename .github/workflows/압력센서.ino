//변수
int Lefthandsecond = A1;
int Righthandsecond = A2;
int Lefthandthird = A3;
int Righthandthird = A4;
int Bottom = A5;

//버튼 상태  0:첩촉x 1:접촉o
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

//버튼 눌린횟수
int buttonCount1 = 0;
int buttonCount2 = 0;
int buttonCount3 = 0;
int buttonCount4 = 0;
int buttonCount5 = 0;

//버튼 눌렸을때 시간측정
unsigned long pressTime1 = 0;
unsigned long pressTime2 = 0;

//메시지 출력 여부
int mainPrinted = 0;
int restartPrinted = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int LeftMove = analogRead(Lefthandsecond);
  int RightMove = analogRead(Righthandsecond);
  int Watchturn = analogRead(Lefthandthird);
  int WatchReverceturn = analogRead(Righthandthird);
  int Hold = analogRead(Bottom);

  if (LeftMove > 10 && buttonState1 == 0) { //입력값이 10초과 + 접촉 상태가 0이였을때 - 눌렀을때
    buttonState1 = 1;
    buttonCount1++;
    Serial.print("LeftMove ");
    Serial.println(buttonCount1);
    pressTime1 = millis();
    mainPrinted = 0; //메시지 출력 초기화
  } else if (LeftMove <= 10 && buttonState1 == 1) {//입력값이 10미만 + 접촉 상태가 1이였을때 - 땠을때
    buttonState1 = 0; // 시간 초기화
    pressTime1 = 0;//시간 초기화
    mainPrinted = 0; //메시지 출력 초기화
  }

  if (RightMove >10 &&buttonState2==0) {
    buttonState2=1;
    buttonCount2++;
    Serial.print("RightMove ");
    Serial.println(buttonCount2);
    pressTime2=millis();
    restartPrinted=0; //메시지 출력 초기화
   } else if (RightMove <=10 &&buttonState2==1){
     buttonState2=0;
     pressTime2=0;
     restartPrinted=0; //메시지 출력 초기화
   }

   if(Watchturn>10&&buttonState3==0){
     buttonState3=1;
     buttonCount3++;
     Serial.print("Watchturn ");
     Serial.println(buttonCount3);
   }else if(Watchturn<=10&&buttonState3==1){
     buttonState3=0;
   }

   if(WatchReverceturn>10&&buttonState4==0){
     buttonState4=1;
     buttonCount4++;
     Serial.print("WatchReverceturn ");
     Serial.println(buttonCount4);
   }else if(WatchReverceturn<=10&&buttonState4==1){
     buttonState4=0;
   }

   if(Hold>10&&buttonState5==0){
     buttonState5=1;
     buttonCount5++;
     Serial.print("Hold ");
     Serial.println(buttonCount5);
   }else if(Hold<=10&&buttonState5==1){
     buttonState5=0;
   }

   if(pressTime1>0&&millis()-pressTime1>=3000&&Watchturn>10&&!mainPrinted){ //버튼 눌림 + 3초 경과 + 저항 10보다 큼 + 메인 출력변수가 0일때(1번싱행되는거 확인용) 
     pressTime1=millis();
     Serial.println("Main");
     mainPrinted=1; //메시지 출력 표시
   }

   if(pressTime2>0&&millis()-pressTime2>=3000&&WatchReverceturn>10&&!restartPrinted){
     pressTime2=millis();
     Serial.println("Restart");
     restartPrinted=1; //메시지 출력 표시
   }

   delay(100);
}
