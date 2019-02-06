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
void setArrivo()
{
  lcd.setCursor(7, 2);
  lcd.print(arrivo);
  
  while (digitalRead(conferma) == HIGH )
  {
    if (digitalRead(meno) == LOW)
    {
      if (arrivo == 100)
      {
        lcd.setCursor(9, 2);
        lcd.print(" ");
      }
      if (arrivo > 30)
      {
        arrivo--;
      }
      lcd.setCursor(7, 2);
      lcd.print(arrivo);
      delay(200);
    }
    if (digitalRead(piu) == LOW)
    {
      if (arrivo < 100)
      {
        arrivo++;
      }
      
      lcd.setCursor(7, 2);
      lcd.print(arrivo);
      delay(200);
    }
  }
  lcd.setCursor(7, 2);
  lcd.print(arrivo);
  }
  void Valore(int v,int giocatore)
  {
    lcd.clear();
    lcd.setCursor(7, 2);
    lcd.print(v);
    lcd.setCursor(0, 0);
    lcd.print("Scegli un valore");
  while (digitalRead(conferma) == HIGH )
  {
    if (digitalRead(meno) == LOW)
    {
      if (v == 6)
      {
        lcd.setCursor(9, 2);
        lcd.print(" ");
      }
      if (v > 0)
      {
        v--;
      }
      lcd.setCursor(7, 2);
      lcd.print(v);
      delay(200);
    }
    if (digitalRead(piu) == LOW)
    {
      if (v < 6)
      {
        v++;
      }
      
      lcd.setCursor(7, 2);
      lcd.print(v);
      delay(200);
    }
  }
  
    if(v == ValorePrecedente)
    {
    Valore(v,giocatore);
    return;
    }
    if(7-ValorePrecedente==v)
    {
      Valore(v,giocatore);
      return;
    }
    if(prima==false&&v==0)
    {
      Valore(v,giocatore);
      return;
    }
    
  lcd.setCursor(7, 2);
  lcd.print(v);
  Verifica(v,giocatore);
  tot+=v;
  ValorePrecedente=v;
  prima=false;
    }
 void Controlla(int v,int giocatore)
 {
 
  }
  void Gioca()
  {
    while(tot<arrivo)
    {
       lcd.clear();
       lcd.setCursor(0, 0);
       giocatore=1;
       lcd.print("Giocatore ");
       lcd.print(giocatore);
       delay(1000);
       Valore(v1,giocatore);
       lcd.clear();
       lcd.setCursor(0, 0);
       giocatore=2;
       lcd.print("Giocatore ");
       lcd.print(giocatore);
       delay(1000);
       Valore(v2,giocatore);
    }
    }
    void Verifica(int v,int giocatore)
    {
      if(tot+v==arrivo)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Il vincitore e");
        lcd.setCursor(0, 1);
        lcd.print("il giocatore");
        lcd.print(giocatore);
        delay(2000);
        }
        if(tot+v>arrivo)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Il perdente e");
        lcd.setCursor(0, 1);
        lcd.print("il giocatore");
        lcd.print(giocatore);
        delay(2000);
          }
      }
      
void loop() {
 Gioca();
 lcd.clear();
 lcd.print(tot);
 delay(9000);
}
