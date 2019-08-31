//Performs an invert function on one input
int INV(int x){
  int output = !x;
  return output;
}

//Performs an AND function on two inputs
int AND(int x, int y){
  int output = x && y;
  return output;
}

int THREEAND(int x, int y, int z){
   int out = x && y && z;
   return out; 
}

int FOURAND(int x, int y, int z, int q){
   int out = x && y && z && q;
   return out; 
}

int FIVEAND(int x, int y, int z, int q, int h){
   int out = x && y && z && q && h;
   return out;
}

//Performs a NAND function on two inputs
int NAND(int x, int y){
  int output = INV(AND(x,y));
  return output;  
}

//Performs an OR function on two inputs
int OR(int x, int y){
  int output = x || y;
  return output;
}

int THREEOR(int x, int y, int z){
   int out = x || y || z;
   return out; 
}

int FOUROR(int x, int y, int z, int q){
   int out = x || y || z || q;
   return out; 
}

int FIVEOR(int x, int y, int z, int q, int h){
   int out = x || y || z || q || h;
   return out; 
}

int SIXOR(int x, int y, int z, int q, int h, int o){
   int out = x || y || z || q || h || o;
   return out; 
}

//Performs a NOR function on two inputs
int NOR(int x, int y){
  int output = INV(OR(x,y));
  return output;
}

//Simulates the behavior of a 2x1 MUX; s = switch
int MUX(int x, int y, int s){
  int AND1 = AND(x,INV(s));
  int AND2 = AND(y,s);
  int OR1 = OR(AND1,AND2);
  return OR1;
}

///Simulates the behavior of a 4x1 MUX; s = switch
int FOURBIT_MUX(int a, int b, int c, int d, int s, int h){
  int Q1 = MUX(a,b,s);
  int Q2 = MUX(c,d,s);
  int t_O = MUX(Q1,Q2,h);
  return t_O;
}

//Performs an XOR function on two inputs
int XOR(int x, int y){
  int AND1 = AND(INV(x), y);
  int AND2 = AND(x, INV(y));
  int OUT = OR(AND1,AND2);
  return OUT; 
}

//Performs an XNOR function on two inputs
int XNOR(int x, int y){
  int out = INV(XOR(x,y));
  return out;
}

//Simulates the behavior of a 2-BIT Adder
  int TWOBIT_ADD(int a, int b, int carry_in, int* carry0){
  int XOR_1 = XOR(a,b);
  int XOR_2 = XOR(XOR_1, carry_in);
  int AND_1 = AND(carry_in, XOR(a,b));
  int OR_1 = OR(AND_1, AND(a,b));
  *carry0 = OR_1;
  return XOR_2;
}
  
//Simulates the behavior of a 4-BIT Adder; adds values of P and Q; outs correspond to carrout bits.
void FOURBIT_ADD(int P0, int P1, int P2, int P3, int Q0, int Q1, int Q2, int Q3, int* carry_out, int* out1, int* out2, int* out3, int* out4){
  int c1i, c2i, c3i, c4i, c1o, c2o, c3o, c4o;
  c1i = 0;
  *out1 = TWOBIT_ADD(P0,Q0,c1i,&c1o);
  c2i = c1o;
  *out2 = TWOBIT_ADD(P1,Q1,c2i,&c2o);
  c3i = c2o;
  *out3 = TWOBIT_ADD(P2,Q2,c3i,&c3o);
  c4i = c3o;
  *out4 = TWOBIT_ADD(P3,Q3,c4i,&c4o);
  *carry_out = c4o;
}
void SR_LATCH(int S, int R, int* Q ,int* Q_NOT){
  *Q_NOT = NOR(S,*Q);
  *Q = NOR(R,*Q_NOT);
}

//Simulates the behavior of a D-Latch
void D_LATCH(int D, int E, int* Q, int* Q_NOT){
   int S,R;
   S = AND(D,E);
   R = AND(INV(D),E);
   SR_LATCH(S,R,Q,Q_NOT); 
}

//Simulates the behavior of DFF
void D_FF(int D, int clk, int* Q0, int* Q0_NOT, int* Q, int* Q_NOT){
   D_LATCH(D,INV(clk),Q,Q_NOT);
   D_LATCH(*Q, clk, Q0, Q0_NOT);
}

//Simulates the behavior of a 4 bit register
//Four D-Flip-Flops
void FOURBIT_REG(int clk, int D0, int D1, int D2, int D3, int* QM, int* QM_NOT,int* QM1, int* QM1_NOT, int* QM2, int* QM2_NOT, int* QM3, int* QM3_NOT, int* Q1, int* Q1_NOT, int* Q2, int* Q2_NOT, int* Q3, int* Q3_NOT,int* Q4, int* Q4_NOT){
   D_FF(D0,clk,Q1,Q1_NOT,QM,QM_NOT);
   D_FF(D1,clk,Q2,Q2_NOT,QM1,QM1_NOT);
   D_FF(D2,clk,Q3,Q3_NOT,QM2,QM2_NOT);
   D_FF(D3,clk,Q4,Q4_NOT,QM3,QM3_NOT);
}

//4 bit adder using a register
void SEQ_4ADD(int clk,int D0,int D1,int D2,int D3, int* QM, int* QM_NOT,int* QM1, int* QM1_NOT, int* QM2, int* QM2_NOT, int* QM3, int* QM3_NOT, int* Q1_NOT, int* Q2_NOT, int* Q3_NOT, int* Q4, int* Q4_NOT, int* Q0, int* Q1, int* Q2, int* Q3, int* carry0, int* carry1, int* carry2, int* carry3, int* carry4){
   FOURBIT_REG(clk,D0,D1,D2,D3,QM,QM_NOT,QM1,QM1_NOT,QM2,QM2_NOT,QM3,QM3_NOT,Q1,Q1_NOT,Q2,Q2_NOT,Q3,Q3_NOT,Q4,Q4_NOT);
   FOURBIT_ADD(D0,D1,D2,D3,*Q1,*Q2,*Q3,*Q4,carry0,carry1,carry2,carry3,carry4);
}

//Compares A to B
void COMPARE(int a, int b, int eq, int lt, int gt, int* eqN, int* ltN, int* gtN){
   *eqN = OR(FIVEAND(eq,INV(lt),INV(gt),INV(a),INV(b)),FIVEAND(eq,INV(lt),INV(gt),a,b));
   *gtN = FIVEOR(FIVEAND(eq,INV(lt),INV(gt),a,INV(b)),FIVEAND(INV(eq),INV(lt),gt,INV(a),INV(b)),FIVEAND(INV(eq),INV(lt),gt,INV(a),b),FIVEAND(INV(eq),INV(lt),gt,a,INV(b)),FIVEAND(INV(eq),INV(lt),gt,a,b));
   *ltN = FIVEOR(FIVEAND(eq,INV(lt),INV(gt),INV(a),b),FIVEAND(INV(eq),lt,INV(gt),INV(a),INV(b)),FIVEAND(INV(eq),lt,INV(gt),INV(a),b),FIVEAND(INV(eq),lt,INV(gt),a,INV(b)),FIVEAND(INV(eq),lt,INV(gt),a,b));  
}

void FOURBIT_COUNT(int clk, int* out1_New, int* out2_New, int* out3_New, int* out4_New, int* carry0, int* out1, int* out2, int* out3, int* out4, int* QM, int* QM_NOT, int* QM1, int* QM1_NOT, int* QM2, int* QM2_NOT, int* QM3, int* QM3_NOT, int* Q_NOT, int* Q1_NOT, int* Q2_NOT, int* Q3_NOT, int* Q4_NOT){
  FOURBIT_ADD(1,0,0,0,*out1_New,*out2_New,*out3_New,*out4_New,carry0,out1,out2,out3,out4);
  FOURBIT_REG(clk,*out4,*out3,*out2,*out1,QM,QM_NOT,QM1,QM1_NOT,QM2,QM2_NOT,QM3,QM3_NOT,out4_New,Q1_NOT,out3_New,Q2_NOT,out2_New,Q3_NOT,out1_New,Q4_NOT);
}
