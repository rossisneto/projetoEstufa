// Projeto de controlador para estufa
//

#define LED_PIN 7
#define BUZZER_PIN 6
#define RELAY_PIN 5
#define TEMP_SENSOR A0


float volt = 0.0;
float temp_C = 0.0;

void setup()
{
  //Incializando a serial
  Serial.begin(9600);
  
  //definindo as portas
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (TEMP_SENSOR, INPUT);
  
  //Testando o funcionamento do LED e do Buzzer e do Fan
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(1000); // Wait for 2000 millisecond(s)
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(7, LOW);
}

void loop()
{
  volt=analogRead(TEMP_SENSOR) * (5.0 / 1023.0);
  temp_C = (volt-0.5) * 100;
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  Serial.println("Inciando a leitura do sensor de temperatura...");
  volt=analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
  temp_C = ((volt - 0.5) * 100);
  Serial.print("Temperatura: ");
  Serial.println(temp_C);
  
  //Verificando se a temperatura é maior que 30 para acionar o ventilador
  if(temp_C>=30.0){
  	//Habilitando o ventilador
    Serial.println("Ventilador ativado");
    digitalWrite(RELAY_PIN, HIGH);
    
    if(temp_C>50.0){
      	//Habilitando o modo de emergencia
  		Serial.println("EMERGÊNCIA!!!");
      	digitalWrite(LED_PIN, HIGH);
    	digitalWrite(BUZZER_PIN, HIGH);
    }
    else{
    	//Desabilitando o modo de emergencia
      	digitalWrite(LED_PIN, LOW);
    	digitalWrite(BUZZER_PIN, LOW);
    }
    
  }
  else{
  	//Serial.println("Ventilador desligado");
    digitalWrite(RELAY_PIN,LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}