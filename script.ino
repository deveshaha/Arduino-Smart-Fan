int ledVerde = 7;
int ledRojo = 6;
int ventilador = 13;
int interruptor = 8;

void encenderVerde(){
	digitalWrite(ledVerde, HIGH);
}
void encenderRojo(){
	digitalWrite(ledRojo, HIGH);
}
void apagarVerde(){
	digitalWrite(ledVerde, LOW);
}
void apagarRojo(){
	digitalWrite(ledRojo, LOW);
}
void ventiladorOn(){
	digitalWrite(ventilador, HIGH);
}
void ventiladorOff(){
	digitalWrite(ventilador, LOW);
}

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(interruptor, INPUT);

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ventilador, OUTPUT);

}

void loop(){

    int lecturaInterruptor = digitalRead(interruptor);

    // Calcular temperatura
    float lectura = analogRead(A0);
    float tempCentigrados = (lectura * (500.0 / 1024.0) ) - 50.0;
    Serial.println(tempCentigrados);

    if (lecturaInterruptor == HIGH)
    {
        encenderVerde();
        apagarRojo();
        ventiladorOn();
    } else if (tempCentigrados > 30){
        encenderVerde();
        apagarRojo();
        ventiladorOn();
    } else {
        encenderRojo();
        apagarVerde();
        ventiladorOff();
    }
    
    
  delay(1000);
}




