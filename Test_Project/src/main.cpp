#include <Arduino.h>

int DV=0;
int CHUC=0;
int TRAM =0;
int NGHIN=0;
int num =5;

int KDV=14;
int KCHUC=12;
int KTRAM=16;
int KNGHIN=19;
int a=18;
int b=4;
int c=26;
int d=25;
int e=33;
int f=5;
int g=27;


void setup() {
  pinMode(KDV, OUTPUT);
  pinMode(KCHUC, OUTPUT);
  pinMode(KTRAM, OUTPUT);
  pinMode(KNGHIN, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);

}

void loop ()
{
  digitalWrite(KCHUC, 0);
}