//***************************************************************************************************************
// Universidad del Valle de Guatemala 
// BE3015 - Electrónica Digital 2
// Jeremy Mejía 
// Laboratorio #6
// Arduino
// Carné: 19846
//***************************************************************************************************************

//***************************************************************************************************************
// Librerías
//***************************************************************************************************************

//***************************************************************************************************************
// Definición de Pines
//***************************************************************************************************************

//Botones
#define btn1 PF_0
#define btn2 PF_4 
#define pot1 PE_3

//Comunicación Serial

#define Rx PB_0
#define Tx PB_1

//Pines de los leds
#define ledR PF_1
#define ledA PF_2
#define ledV PF_3

//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************
//void configurarPWM(void);
void Incrementar(void);
void Decrementar(void);

//***************************************************************************************************************
// Variables Globales
//***************************************************************************************************************

int contador = 0; 
int voltaje = 0;
int voltaje1 = 0; 

//***************************************************************************************************************
// Configuración
//***************************************************************************************************************

void setup() {
  Serial1.begin(115200); 
  Serial.begin(115200); 

  //Salida de los pines 
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

}

//***************************************************************************************************************
// Loop Principal
//***************************************************************************************************************

void loop() {

  voltaje1 = analogRead(pot1);
  voltaje1 = map(voltaje1, 0, 4095, 0, 255);
  analogWrite(ledA, voltaje1);
  Serial1.write(voltaje1);
  Serial.println(voltaje1);
/*
  if (Serial1.available() > 0){
     int valor = Serial1.read();  
     analogWrite(ledR, valor);
  }*/
  
  if(digitalRead(btn1) == LOW){
    Incrementar(); 
   }
   
  if(digitalRead(btn2) == LOW){
    Decrementar(); 
   }
  
}

//***************************************************************************************************************
// Función Incrementar
//***************************************************************************************************************
void Incrementar(void){

  if(digitalRead(btn1) == LOW && contador == 0){
    analogWrite(ledV, contador);
    contador = contador + 1; 
    Serial1.print(contador);
    delay(500);
    }
    
  else if(digitalRead(btn1) == LOW && contador == 1){
    analogWrite(ledV, contador);
    Serial1.print(contador);
    contador = contador + 1; 
    delay(500);
    }
  else if(digitalRead(btn1) == LOW && contador == 255){
    analogWrite(ledV, contador);
    contador = contador;
    Serial1.print(contador);
    delay(500);
    }
  else if(digitalRead(btn1) == LOW && contador++){
    analogWrite(ledV, contador - 1);
    Serial1.print(contador);
    delay(500);
    } 
}


//***************************************************************************************************************
// Función Decrementar
//***************************************************************************************************************

void Decrementar(void){

  if(digitalRead(btn2) == LOW && contador == 0){
    analogWrite(ledV, contador);
    Serial1.print(contador);
    delay(500);
    }
  else if(digitalRead(btn2) == LOW && contador == 1){
    analogWrite(ledV, contador - 1);
    Serial1.print(contador - 1);
    delay(500);
    }
  else if(digitalRead(btn2) == LOW && contador--){
    analogWrite(ledV, contador - 1);
    Serial1.print(contador);
    delay(500);
    }
}
