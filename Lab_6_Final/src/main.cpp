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

#include <Arduino.h>
#include <LiquidCrystal.h>

//***************************************************************************************************************
// Definición de Pines
//***************************************************************************************************************

//Definición de entradas
#define Pot1 13 // potenciómetro 1
#define Pot2 12 // potenciómetro 2

//Definición de pines de salidas LCD
#define RS 2
#define E 4 
#define D4 18
#define D5 19
#define D6 21
#define D7 22

//Comunicación Serial
#define Tx 1
#define Rx 3


//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************
/*
void configurarPWM(void);
void Incremento(void);
void Decremento(void);*/

//***************************************************************************************************************
// Variables Globales
//***************************************************************************************************************

int contador = 0;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
int adcRaw;
int voltaje;
int voltaje2; 
int valor1; 

//***************************************************************************************************************
// Configuración
//***************************************************************************************************************

void setup() {
  Serial2.begin(115200);
  Serial.begin(115200);
  LCD.begin(16, 2);
}

//***************************************************************************************************************
// Loop Principal
//***************************************************************************************************************

void loop() {
  voltaje = analogRead(Pot1);
  voltaje = map(voltaje, 0, 4095, 0, 255);

  //Serial2.write(voltaje);
/*
  
  if (Serial2.available() > 0){
    int valor = Serial2.read();  
    LCD.setCursor(11, 1);
    LCD.print(valor); 
  }
*/  

  if (Serial2.available() > 0){
    int valor = Serial2.read();  
    LCD.setCursor(11, 1);
    LCD.print(valor); 
    Serial.print(valor);
  }
  
  LCD.clear();
  LCD.print("Rojo ");
  LCD.print("Verde ");
  LCD.print("Azul ");
  LCD.setCursor(0, 1);
  LCD.print(voltaje);
  
  
  delay(250);

}
