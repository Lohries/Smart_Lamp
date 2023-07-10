const int LDR = A0;
const int LED1 = 9;
float maxLuminus = 200;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
}

void loop()
{
  float valor = analogRead(LDR);
  float voltagem = valor * (5.0/1023.0);
  float luminus = map(voltagem, 0, 5, 255, 0);  

  if (luminus <= maxLuminus) { 
    analogWrite(LED1, 0); 
   
  } else { 
    analogWrite(LED1, luminus);
 
  }

  Serial.print("Intensidade luminosa: ");
  Serial.print(voltagem * 100);
  Serial.print(" lux, luminosidade: ");
  Serial.println(luminus);  
  delay(1000);
}