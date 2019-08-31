#include "C:\Users\dagisg56\Downloads\DL\Functions\Functions.ino"

// 4BitAdder implemented on 7 segment display.

int Q0 = 0;
int Q1 = 0;
int Q2 = 0;
int Q3 = 0;
int Q4 = 0;

int Q0_NOT = 0;
int Q1_NOT = 0;
int Q2_NOT = 0;
int Q3_NOT = 0;
int Q4_NOT = 0;

int QM = 0;
int QM1 = 0;
int QM2 = 0;
int QM3 = 0;

int QM_NOT = 1;
int QM1_NOT = 1;
int QM2_NOT = 1;
int QM3_NOT = 1;

int out1 = 0;
int out2 = 0;
int out3 = 0;
int out4 = 0;

int out1_New = 0;
int out2_New = 0;
int out3_New = 0;
int out4_New = 0;

int carry_out = 0;

void setup(){

    Serial.begin(9600);

    //Clock and D Inputs
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    pinMode(A4,INPUT);

    //Outputs to LED
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
  }
  
void loop(){

    int clk = digitalRead(A0);
    int D0 = digitalRead(A1);
    int D1 = digitalRead(A2);
    int D2 = digitalRead(A3);
    int D3 = digitalRead(A4);

    //Q's stored in register
    //D's are temporary
    FOURBIT_REG(clk,D0,D1,D2,D3,&QM,&QM_NOT,&QM1,&QM1_NOT,&QM2,&QM2_NOT,&QM3,&QM3_NOT,&Q1,&Q1_NOT,&Q2,&Q2_NOT,&Q3,&Q3_NOT,&Q4,&Q4_NOT);
    FOURBIT_ADD(D0,D1,D2,D3,Q1,Q2,Q3,Q4,&carry_out,&out4,&out3,&out2,&out1);

    //7 segment display (using A as out1, B as out2, C as out3, D as out4)
    int A = SIXOR(AND(INV(out1),out3),AND(out2,out3),AND(out1,INV(out4)),AND(INV(out2),INV(out4)),THREEAND(INV(out1),out2,out4),THREEAND(out1,INV(out2),INV(out3)));
    int B = FIVEOR(AND(INV(out2),INV(out3)),AND(INV(out2),INV(out4)),THREEAND(INV(out1),INV(out3),INV(out4)),THREEAND(INV(out1),out3,out4),THREEAND(out1,INV(out3),out4));
    int C = FIVEOR(AND(INV(out1),out2),AND(out1,INV(out2)),AND(INV(out3),out4),AND(INV(out1),INV(out3)),AND(INV(out1),out4));
    int D = FIVEOR(AND(out1,INV(out3)),THREEAND(out2,out3,INV(out4)),THREEAND(INV(out2),out3,out4),THREEAND(INV(out1),INV(out2),INV(out4)),THREEAND(out2,INV(out3),out4));
    int E = FIVEOR(AND(out1,out2),AND(out3,INV(out4)),AND(out1,out3),AND(out1,INV(out4)),AND(INV(out2),INV(out4)));
    int F = FOUROR(AND(out1,INV(out2)),AND(INV(out3),INV(out4)),THREEAND(INV(out1),out2,INV(out3)),THREEAND(INV(out1),out2,INV(out4)));
    int G = FIVEOR(AND(out1,INV(out2)),AND(out3,INV(out4)),AND(out1,out4),AND(INV(out2),out3),THREEAND(INV(out1),out2,INV(out3)));
    int H = carry_out;

    Serial.print("Q+D: ");
    Serial.print(out4);
    Serial.print(out3);
    Serial.print(out2);
    Serial.print(out1);
    Serial.println(" ");

    digitalWrite(2,A);
    digitalWrite(3,B);
    digitalWrite(4,C);
    digitalWrite(5,D);
    digitalWrite(6,E);
    digitalWrite(7,F);
    digitalWrite(8,G);
    digitalWrite(9,H);
  }
