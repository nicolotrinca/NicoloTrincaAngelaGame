#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int meno = 6;
const int conferma = 7;
const int piu = 8;

int arrivo = 30;
int tot = 0;

bool prima=true;

int ValorePrecedente=10;

int giocatore=1;
   
int v1 = 0;
int v2 = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Angela Game");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scegli l arrivo");
  pinMode(meno, INPUT); //meno
  pinMode(conferma, INPUT); //conferma
  pinMode(piu, INPUT); //più
  digitalWrite(meno, HIGH);
  digitalWrite(conferma, HIGH);
  digitalWrite(piu, HIGH);
  setArrivo();
}