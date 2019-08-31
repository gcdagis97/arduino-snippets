#include "C:\Users\dagisg56\Desktop\email\Functions\Functions.ino"

//Program simulates an SR-Latch

//Initializing outputs to 0 to start
int out0 = 0;
int out1 = 0;


//SR-Latch function
//Inputs Set, Reset; Outputs Q, Q_NOT
void SR_Latch(int S, int R, int* Q ,int* Q_NOT) {
    //Output Q is inputs RESET and Q_NOT NOR'ed together
    *Q = NOR(R,*Q_NOT);
  
    //Output Q_NOT is inputs SET and Q NOR'ed together
    *Q_NOT = NOR(S,*Q);
}

void setup() {
    //Set and Reset Pins
    pinMode(2,INPUT);
    pinMode(3,INPUT);

    //Q and Q_NOT
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
}

void loop() {
    //Set and Reset Pins are read
    int set = digitalRead(3);
    int reset = digitalRead(2);

    //SR-Latch function, pin 6 acting as Q, pin 7 acting as Q_NOT
    SR_Latch(set,reset,&out0,&out1);
  
    digitalWrite(6,out0);     // Value of Q is written to pin 6
    //digitalWrite(7,out1);   // Value of Q_NOT is written to pin 7
}
