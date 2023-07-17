void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int Cds = analogRead(A1);
  
  Serial.print("Cds = ");
  Serial.println(Cds);
  
  if (Cds < 400)
    Serial.print("Generate Trash line\n");
}
