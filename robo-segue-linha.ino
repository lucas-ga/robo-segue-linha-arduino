#include <AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(115200);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  verificaSensorIR();
}

void verificaSensorIR() {
  int sensorA = digitalRead(A0);
  int sensorB = digitalRead(A1);
  int sensorC = digitalRead(A2);
  int sensorD = digitalRead(A3);
  int sensorE = digitalRead(A4);

  int somaEsquerda = sensorA+sensorB;
  int somaDireita = sensorD+sensorE;

  if (somaEsquerda > somaDireita) {
    viraEsquerda();
    return;
  }

  if (somaDireita > somaEsquerda) {
    viraDireita();
    return;
  }

  if ((somaDireita == somaEsquerda) && sensorC == LOW) {
    segueReto();
    return;
  }

  pararMotor();
}s

void viraEsquerda() {
  Serial.println("viraEsquerda");
  ligarMotor();
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  
}

void viraDireita() {
  Serial.println("viraDireita");
  ligarMotor();
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  
}

void segueReto() {
  Serial.println("segueReto");
  ligarMotor();
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void ligarMotor() {
  Serial.println("ligarMotor");
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void pararMotor() {
  Serial.println("pararMotor");
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}