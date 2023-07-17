#define flexPin1 A1
#define flexPin2 A2

void setup()
{                   
  Serial.begin(9600);
}

void loop()
{
  int flexValue1;
  int flexValue2;
  
  flexValue1 = analogRead(flexPin1);
  flexValue2 = analogRead(flexPin2);
  
  Serial.print("flex sensor 1 = ");
  Serial.println(flexValue1);

  Serial.print("flex sensor 2 = ");
  Serial.println(flexValue2);
  
  if (flexValue1 < 20 && flexValue2 < 20)
  {
    Serial.print("hard drop\n");
    while (flexValue1 < 20 && flexValue2 < 20)
    {
      flexValue1 = analogRead(flexPin1);
      flexValue2 = analogRead(flexPin2);
    }
  }
  else if (flexValue1 < 20)
  {
    Serial.print("down\n");
  }
  else if (flexValue2 < 20)
  {
    Serial.print("down\n");
  }
  
  delay(20);
}
