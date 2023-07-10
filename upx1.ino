int led = 10;
int ldr = A0;
int pwm = 0;
int mem;
int pot = A1;
int bot = 7;
bool sensor;
float MaxLuminus = 200;
void setup() {
  pinMode(10, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(bot, INPUT_PULLUP);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}
void loop() {
  sensor = digitalRead(bot);
  if (sensor == 1) {   
  int Valor = analogRead(ldr);
  float voltagem = Valor * (5.0 / 1023.0);
  int luminus = map(voltagem, 0, 5, 255, 0);
    if (luminus >= MaxLuminus) {     
  analogWrite(led, luminus);   
  Serial.print("Intensidade luminosa: ");
  Serial.print(voltagem * 100);
  Serial.print(" lux, luminosidade: ");
  Serial.println(luminus);
  delay(500);
    }
   else  {
   analogWrite(led, 0);    
     }
    }  
  else {
    mem = analogRead(pot);
	pwm = map(mem, 0, 1023, 0, 255);
	analogWrite(led, pwm);
  } }

