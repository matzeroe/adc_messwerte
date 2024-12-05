#include <Arduino.h>
#include <stdio.h>
int adc_array[30]; // array of 30 integers
int counter=0; // counter for the array
void adc_calc(int array[]);
void adc_lesen(int array[]);
void setup() {
    pinMode(39, INPUT); // set pins 0 to 7 as input
}

void loop() {
    delay(500);
  adc_lesen(adc_array);
  adc_calc(adc_array);
}

void adc_lesen(int f_adc_array[]) {
  f_adc_array[counter]=analogRead(39); // read the value of the analog pin 39 and store it in the array
  counter++;
  }

void adc_calc(int f_adc_array[]){
   if(counter==30) { 
    int arithmetischer_mittelwert=0;
    int max=0;
    int min=1023;
        for(int i=0; i<30; i++) { // 
          arithmetischer_mittelwert = arithmetischer_mittelwert+f_adc_array[i];
        }
      arithmetischer_mittelwert= (arithmetischer_mittelwert/30);
        for(int i=0; i<30; i++) { // 
          if(f_adc_array[i]>max) {
            max=f_adc_array[i];
          }
        }
        for(int i=0; i<30; i++) { // 
          if(f_adc_array[i]<min) {
            min=f_adc_array[i];
          }
        }
  Serial.println("Maximalwert:"+ max);
  Serial.println("Minimalwert:" + min);
  Serial.println("Arithmetischer Mittelwert:" + arithmetischer_mittelwert);  
}}
