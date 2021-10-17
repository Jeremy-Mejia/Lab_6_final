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

#define btn1 PF_0
#define btn2 PF_4 

//Pines de los leds
#define ledR PF_1
#define ledA PF_2
#define ledV PF_3

//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************

void Incrementar(void);
void Decrementar(void);

//***************************************************************************************************************
// Variables Globales
//***************************************************************************************************************

int contador = 0; 

//***************************************************************************************************************
// Configuración
//***************************************************************************************************************

void setup() {
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
  if(digitalRead(btn1) == LOW){
    Incrementar(); 
   }
   
  if(digitalRead(btn1) == LOW){
    Decrementar(); 
   }
  
}

//***************************************************************************************************************
// Función Incrementar
//***************************************************************************************************************
void Incrementar(){

  if(btn1 == LOW && contador == 0 ){
    digitalWrite(ledV, valor)
   }
}


//***************************************************************************************************************
// Función Decrementar
//***************************************************************************************************************
