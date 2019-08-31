#include "C:\Users\USER\Desktop\Functions.ino"

//Program simulates an SR-Latch

//Initializing outputs to 0 to start
int out0 = 0;
int out1 = 0;


//SR-Latch function
//Inputs Set, Reset; Outputs Q, Q_NOT
void SR_LATCH(int S, int R, int* Q ,int* Q_NOT){

    //Output Q is inputs RESET and Q_NOT NOR'ed together
    *Q = NOR(R,*Q_NOT);
  
    //Output Q_NOT is inputs SET and Q NOR'ed together
    *Q_NOT = NOR(S,*Q);
}

//Simulates a D-Latch given values for D and Enable inputs
void D_LATCH(int D, int E, int* Q, int* Q_NOT){
    //portion before SR_Latch
    int S,R;
    S = AND(D,E);
    R = AND(INV(D),E);

    //SR_Latch remaining inputs
    SR_LATCH(S,R,Q,Q_NOT); 
}

void setup() {
    //D and Enable Pins
    pinMode(2,INPUT);
    pinMode(3,INPUT);

    //Q and Q_NOT
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
}

void loop() {
    //D and Enable Pins are read
    int D = digitalRead(3);
    int E = digitalRead(2);

    D_LATCH(D,E,&out0,&out1);
    digitalWrite(6,out0);     // Value of Q is written to pin 6
    //digitalWrite(7,out1);   // Value of Q_NOT is written to pin 7
}
