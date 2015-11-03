

int diodaPin = 13;  // to już jest dla nas jasne :)
int potPin = 0;     // przypisujemy do zmiennej numer wejścia analogowego
int pot;            // zmienna w której będziemy zapisywać "wartość" potencjometru
int przerwa;        // zmienna w której będziemy zapisywać szybkość migania
 
void setup() {
  pinMode(diodaPin, OUTPUT);
}
 
void loop() {
  pot = analogRead(potPin);     // odczytujemy A0 i zapisujemy w zmiennej pot
 
  /*
  Wykorzystana niżej funkcja map() służy do przeliczenia jednego zakresu liczb
  na inny. W naszym wypadku przeliczy liczby z zakresu od 0 do 1023 (wartość
  odczytana z A0), na liczby z zakresu od 50 do 3000 (odstęp między zapalaniem
  i gaszeniem diody). Przeliczony zakres liczb zostanie zapisany w zmiennej przerwa.
  */
 
  przerwa = map(pot, 0, 1000, 0, 500);
 
  digitalWrite(diodaPin, HIGH);
  delay(przerwa);               // przerwa zależna od położenia potencjometru
  digitalWrite(diodaPin, LOW);
  delay(przerwa);               // przerwa zależna od położenia potencjometru
}
