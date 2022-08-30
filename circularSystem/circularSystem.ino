byte incomingByte;
/* Definimos el estado del relay */
#define RELAY_ON 1
#define RELAY_OFF 0
/* Definimos el pin usado por el relay */
#define RELAY_1 2  //Circular 1
#define RELAY_2 3  //Circular 2
#define RELAY_3 4  //Circular 3
#define RELAY_4 5  //Circular 4
#define RELAY_5 8  //Circular 5
#define RELAY_6 9  //Circular 6

#define RELAY_7 6  //instalación INFO 2 Lampara
#define RELAY_8 7  //instalación INFO 2 Lampara

#define NUM_LAMPS 6
#define T_LAP 1000

float tPerLamp = 1000 / 6;//TODO
int tONArray[] = {166, 166, 166, 166, 166, 166};
int tOFFArray[] = {0, 0, 0, 0, 0, 0};

int tONLamp1 = 500;
int tONLamp2 = 500;

int tBeforeLamps = 0;
int tBeforeCircular = 0;
unsigned long timeWaiting = 30000;//120000 -> 2 min // 60000 --> 1 min  // 30000 --> 30 seg
unsigned long mySavedTimer = 0;

bool bAction = true;
bool bInfoLamps = false;
bool bDebug = false;

////////////////SETUP///////////////////
void setup() {

  Serial.begin(9600); // open the serial port at 9600 bps:
  Serial.println("Start Circular system : OFF Press a to Start");


  /* Loaded data */
  Serial.print("Coded times and laps : ");
  Serial.println("Time Lap = " + T_LAP);

  /* Iniciamos PINES */

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(RELAY_6, OUTPUT);
  pinMode(RELAY_7, OUTPUT);
  pinMode(RELAY_8, OUTPUT);


  /* Inicializamos RELAYS ON OFF*/

  digitalWrite(RELAY_1, RELAY_OFF); //OFF    1
  digitalWrite(RELAY_2, RELAY_OFF); //OFF    2
  digitalWrite(RELAY_3, RELAY_OFF); //OFF    3
  digitalWrite(RELAY_4, RELAY_OFF); //OFF    4
  digitalWrite(RELAY_5, RELAY_OFF); //OFF    5
  digitalWrite(RELAY_6, RELAY_OFF); //OFF    6
  digitalWrite(RELAY_7, RELAY_OFF); //OFF    7
  digitalWrite(RELAY_8, RELAY_OFF); //OFF    8


  //INIT Timer VAR
  mySavedTimer = millis();
  if(bDebug)Serial.println((String)"*****************Setup mySavedTimer ="+mySavedTimer+"***********************");

}

////////////////LOOP///////////////////


void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'a') {
      bAction = !bAction;
      if (bAction) {
        mySavedTimer = millis();
        Serial.println("Start");
      }
      else Serial.println("Stop");
    }
  }

  if (bAction) {
    delay(tBeforeCircular);
    circularLoop();

    unsigned long diffTime = millis() - mySavedTimer;
    if(bDebug)Serial.println((String)"mySavedTimer ="+mySavedTimer);
    if(bDebug)Serial.println((String)"millis() ="+millis());
    if(bDebug)Serial.println((String)"timeWaiting() ="+timeWaiting);
    if(bDebug)Serial.println((String)"diffTime ="+diffTime);

    if (diffTime > timeWaiting) {
      if(bDebug)Serial.println((String)"millis() - mySavedTimer = "+diffTime);
      bInfoLamps = true;
      mySavedTimer = millis();
      if(bDebug)Serial.println("mySavedTimer waiting DONE");
    }

    if (bInfoLamps) {
      infoLamps();
      if(bDebug)Serial.println("infoLamps ON");
      bInfoLamps = false;
    }
    delay(tBeforeLamps);
  }

  delay(10);
}

void circularLoop() {
  //1
  digitalWrite(RELAY_1, RELAY_ON);
  delay(tONArray[0]);
  digitalWrite(RELAY_1, RELAY_OFF);
  delay(tOFFArray[0]);
  //2
  digitalWrite(RELAY_2, RELAY_ON);
  delay(tONArray[1]);
  digitalWrite(RELAY_2, RELAY_OFF);
  delay(tOFFArray[1]);
  //3
  digitalWrite(RELAY_3, RELAY_ON);
  delay(tONArray[2]);
  digitalWrite(RELAY_3, RELAY_OFF);
  delay(tOFFArray[2]);
  //4
  digitalWrite(RELAY_4, RELAY_ON);
  delay(tONArray[3]);
  digitalWrite(RELAY_4, RELAY_OFF);
  delay(tOFFArray[3]);
  //5
  digitalWrite(RELAY_5, RELAY_ON);
  delay(tONArray[4]);
  digitalWrite(RELAY_5, RELAY_OFF);
  delay(tOFFArray[4]);
  //6
  digitalWrite(RELAY_6, RELAY_ON);
  delay(tONArray[5]);
  digitalWrite(RELAY_6, RELAY_OFF);
  delay(tOFFArray[5]);

}

void infoLamps() {
  //7
  digitalWrite(RELAY_7, RELAY_ON);
  delay(tONLamp1);
  digitalWrite(RELAY_7, RELAY_OFF);
  //8
  digitalWrite(RELAY_8, RELAY_ON);
  delay(tONLamp1);
  digitalWrite(RELAY_8, RELAY_OFF);
}
