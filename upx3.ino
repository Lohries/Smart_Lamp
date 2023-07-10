int LED1 = 9;
int LED2 = 6;
int LED3 = 5;
int LED4 = 3;
float LDR = A0;
float maxLuminus = 200; 
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}
void loop()
{
  float valor = analogRead(LDR);
  float voltagem = valor * (5.0/1023.0);
  float luminus = map(voltagem, 0, 5, 255, 0);  

  if (luminus <= maxLuminus) { 
    analogWrite(LED1, 0); 
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    analogWrite(LED4, 0);
  } else { 
    analogWrite(LED1, luminus);
    analogWrite(LED2, luminus);
    analogWrite(LED3, luminus);
    analogWrite(LED4, luminus);
  }

  Serial.print("Intensidade luminosa: ");
  Serial.print(voltagem * 100);
  Serial.print(" lux, luminosidade: ");
  Serial.println(luminus);  
  delay(1000);
}




