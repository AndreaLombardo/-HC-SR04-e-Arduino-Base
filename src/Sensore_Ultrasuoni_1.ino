/*
 * Esempio Utilizzo HC-SR04
 *
 * Autore    : Andrea Lombardo
 * Web       : http://www.lombardoandrea.com
 * Articolo  : http://wp.me/p27dYH-Dt
 */

//Definizione dei pin
static int trigger = 8;
static int echo = 9;

//variabili utilizzate per calcolare la distanza
long durata; //tempo che impieghera' il suono a percorrere una certa distanza
long distanza;  //la distanza che ha percorso il suono

void setup() {
  //abilito la comunicaizone seriale per rendermi conto di cio' che accade
  Serial.begin(9600);

  //settiamo il funzionamento dei pin
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  //metto a LOW l'ingresso del PIN echo e del PIN trigger
  digitalWrite(echo, LOW);
  digitalWrite(trigger, LOW);

  //inizializzo le variabili
  durata = 0;
  distanza = 0;
}

void loop() {

  //Invio un impulso HIGH sul pin del trigger
  digitalWrite(trigger, HIGH);
  //lo lascio al valore HIGH per 10 microsecondi
  delayMicroseconds(10);
  //lo riporto allo stato LOW
  digitalWrite(trigger, LOW);

  //ottengo il numero di microsecondi per i quali il PIN echo e' rimasto allo stato HIGH
  //per fare questo utilizzo la funzione pulseIn()
  durata = pulseIn(echo, HIGH);

  // La velocita' del suono e' di 340 metri al secondo, o 29 microsecondi al centimetro.
  // il nostro impulso viaggia in andata e ritorno, quindi per calcoalre la distanza
  // tra il sensore e il nostro ostacolo occorre fare:
  distanza = durata / 29 / 2;

  //invio i dati alla porta seriale cosi' da poterli vedere con il Monitor Seriale
  Serial.print("Durata : ");
  Serial.print(durata);
  Serial.print(" - Distanza : ");
  Serial.println(distanza);

}

