#define PINO_SINAL 12 // O pino unindo Trig e Echo
#define PINO_LED 8 // Porta digital do Arduino

void setup() {
  Serial.begin(9600);
  Serial.println("Testando sensor 3 fios...");
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  long duracao;
  float distancia;

  // 1. Envia o pulso (Pino como SAÍDA)
  pinMode(PINO_SINAL, OUTPUT);
  digitalWrite(PINO_SINAL, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_SINAL, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_SINAL, LOW);

  // 2. Recebe o eco (Pino como ENTRADA)
  pinMode(PINO_SINAL, INPUT);
  duracao = pulseIn(PINO_SINAL, HIGH, 30000); // Timeout de 30ms

  // 3. Calcula a distância
  distancia = (duracao * 0.0343) / 2;

  if (duracao == 0) {
    Serial.println("Erro: Sem resposta do sensor (Verifique a união Trig/Echo)");
  } else {
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }
  
  if (distancia < 15){
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }
  
  delay(200);
}
