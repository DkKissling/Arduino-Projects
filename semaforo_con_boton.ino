// Semáforo con botón peatonal
// declarando parametros
int led_verde = 13;
int led_amarillo = 12;
int led_rojo = 8;
const int BOTON = 7; // pin de entrada botón
int state = 0; //para activar luz roja
void setup() {
// se indica que cada pin es de salidad OUTPUT.
pinMode(led_verde, OUTPUT);
pinMode(led_amarillo, OUTPUT);
pinMode(led_rojo, OUTPUT);   
pinMode(BOTON,INPUT);
digitalWrite(led_verde,HIGH);  //Luz verde encendida.
digitalWrite(led_verde,LOW); //Luz roja apagada
digitalWrite(led_verde,LOW); //Luz Amarilla apagada
}
// lazo a ejecutar continuamente una vez cargado el código en el arduino
void loop(){
digitalWrite(led_verde,HIGH); // encender LED verde
pedestriaBoton();  // se llama la rutina pedestriaBoton
digitalWrite(led_verde,LOW); // apagar LED verde
digitalWrite(led_amarillo,HIGH); // encender LED amarillo
delay(1000); // mantener por 1 segundos
digitalWrite(led_amarillo,LOW); // apagar LED verde
digitalWrite(led_rojo,HIGH); // encender LED rojo
delay(5000);
digitalWrite(led_rojo,LOW); // encender LED rojo
}
void pedestriaBoton(){
  for(int i=1;i<21; i++){
  state=digitalRead(BOTON);
   if (state==0) {
   delay(1000);
   }
    else if (state=1){
   delay(500);
   return;
   }  // cierra lazo else if
  }  // cierra lazo for
 }  //cierra void pedestriaBoton
