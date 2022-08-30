/* Definimos el estado del relay */
#define RELAY_ON 0
#define RELAY_OFF 1
/* Definimos el pin usado por el relay */
#define RELAY_1 2  //instalación circular
#define RELAY_2 3  //instalación INFO 1 Lampara
#define RELAY_3 4  //instalación INFO 2 Lampara


#define tStart1 3500
#define tStart2 0
#define tStart3 0

#define tWatingON1 10000//900000 = 60*1000*15 // 15 minutos , para test poner 1 min -> 10000 ms
#define tWatingON2 6000
#define tWatingON3 6000

void setup(){
  /* Iniciamos los pines que se usan */

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
 
  
  /* Inicializamos el estado en OFF*/
  /* Solo podemos tener un Relay al tiempo abierto */

  digitalWrite(RELAY_1, RELAY_OFF); //OFF    Circular System
  digitalWrite(RELAY_2, RELAY_OFF); //OFF     INFO 1 Lampara
  digitalWrite(RELAY_3, RELAY_OFF); //OFF     INFO 2 Lampara


}
void loop(){

  digitalWrite(RELAY_2, RELAY_ON);
  delay(tWatingON2);
  digitalWrite(RELAY_2, RELAY_OFF);
  
  digitalWrite(RELAY_3, RELAY_ON);
  delay(tWatingON3-tStart1);
  digitalWrite(RELAY_1, RELAY_ON); //tarda 4 segundos en arrancar
  delay(tStart1);//espera a finalizar el tiempo que esperaba usar para ON de circular systema
  digitalWrite(RELAY_3, RELAY_OFF);

  delay(tWatingON1);
  digitalWrite(RELAY_1, RELAY_OFF); //tarda 4 segundos en arrancar
}
