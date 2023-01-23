const int motorPin1 = 5;    // 28BYJ48 In1
const int motorPin2 = 4;    // 28BYJ48 In2
const int motorPin3 = 3;   // 28BYJ48 In3
const int motorPin4 = 2;   // 28BYJ48 In4
int motorSpeed = 1200;   //variable para fijar la velocidad
int stepCounter = 0;     // contador para los pasos
int stepsPerRev = 4096;  // pasos para una vuelta completa
const int numSteps = 8;//8 MEDIOS PASOS
//SE CONFIGURA LOS MEDIOS PASOS, PARA LAS BOBINAS
const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };
  
void setup(){
  //SE CONFIGURA PINES DE CONTROL DE MOTOR
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}
 
void loop(){
  //DA UNA VUELTA COMPLETA
  for (int i = 0; i < stepsPerRev; i++)  {
    clockwise();
    delayMicroseconds(motorSpeed);//RETARDO
  }
  delay(1000);
  //DA UNA VUELTA COMPLETA INVERSA
  for (int i = 0; i < stepsPerRev ; i++)  {
    anticlockwise();
    delayMicroseconds(motorSpeed);
  }
  delay(1000);
}
//VUELTA EN SENTIDO DEL RELOJ
void clockwise(){  
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput(stepCounter);
}
//VUELTA EN SENTIDO DEL ANTI RELOJ 
void anticlockwise(){ 
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput(stepCounter);
}

//HABILITAR CONTROL PARA AVANZAR MEDIOS PASOS
void setOutput(int step){
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
}
