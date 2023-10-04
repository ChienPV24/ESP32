#include <Arduino.h>

void Print_7SEG(byte number);
void Clear();
void hienthi();

int DV = 0;
int CHUC = 0;
int TRAM = 0;
int NGHIN = 0;
int num = 5;

int KDV = 14;
int KCHUC = 12;
int KTRAM = 16;
int KNGHIN = 19;

int a = 18;
int b = 4;
int c = 26;
int d = 25;
int e = 33;
int f = 5;
int g = 27;

void setup()
{
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

void loop()
{
  num = 1029;

  hienthi();
}
void hienthi()
{
  NGHIN = num / 1000;
  TRAM = (num / 100) % 10;
  CHUC = (num % 100) / 10;
  DV = num % 10;
  Clear();
  digitalWrite(KDV, HIGH);
  digitalWrite(KCHUC, LOW);
  digitalWrite(KTRAM, LOW);
  digitalWrite(KNGHIN, LOW);
  Print_7SEG(DV);
  delay(5);
  Clear();
  digitalWrite(KDV, LOW);
  digitalWrite(KCHUC, HIGH);
  digitalWrite(KTRAM, LOW);
  digitalWrite(KNGHIN, LOW);
  Print_7SEG(CHUC);
  delay(5);
  Clear();
  digitalWrite(KDV, LOW);
  digitalWrite(KCHUC, LOW);
  digitalWrite(KTRAM, HIGH);
  digitalWrite(KNGHIN, LOW);
  Print_7SEG(TRAM);
  delay(5);
  Clear();
  digitalWrite(KDV, LOW);
  digitalWrite(KCHUC, LOW);
  digitalWrite(KTRAM, LOW);
  digitalWrite(KNGHIN, HIGH);
  Print_7SEG(NGHIN);
  delay(5);
}

void Clear()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Print_7SEG(byte number)
{
  switch (number)
  {
  case 0:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
  case 1:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
  case 2:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
  case 3:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
  case 4:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  case 5:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  case 6:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  case 7:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
  case 8:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  case 9:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  }
}