/**
PUNTATORI

int var = ... (variabile)
*p = punta al VALORE della variabile
&var = punta all'INDIRIZZO (di memoria) della variabile
**/

int x = 10;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.print("1) ");Serial.println(x);

  f1(x);

  Serial.print("2) ");Serial.println(x);

  f2(&x);
  Serial.print("f2 fuori dalla funzione) ");Serial.println(x);
}

void loop() {}


// FUNZIONE SENZA PUNTATORI
// La funzione si fa una copia della variabile che gli diamo.
// Quindi la nuova n=n+1 non andrà a sovrascrivere la x,
// Ma potrà essere usata solo all'interno della funzione.
void f1(int n) {
  n = n + 1;
  Serial.print("f1 solo dentro la funzione) ");Serial.println(n);
}


// FUNZIONE CON PUNTATORI
// La funzione andrà a modificare il valore della variabile che gli diamo.
// Questo perché con * gli diamo il valore, ovvero il puntatore alla variabile n.
// Quando andiamo a chiamare questa funzione bisognera inserire l'indirizzo della variabile con &
void f2(int *n) {
  *n = *n +1;
}

