const int row[8] = { 2, 3,4,5,6,7,8,9 };
const int col[8] = { 12,13,14,15,16,17,18,19 };

void setup() {
  // initialize the I/O pins as outputs iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], LOW);
  }
}

void loop() {
  for (int x = 0; x < 8; x++) {
    for (int y = 8; y >=0; y--) {
     // digitalWrite(row[x], LOW);
      digitalWrite(row[y], LOW);     // turn on the row
      digitalWrite(col[y], HIGH);
      // digitalWrite(row[y+1], LOW); 
      // digitalWrite(row[y+2], LOW);
      // digitalWrite(row[5-y], LOW);
      // digitalWrite(row[6-y], LOW); 
      // digitalWrite(row[7-y], LOW);     // turn on the row
      // digitalWrite(col[7-y], HIGH);
      //digitalWrite(col[y+1], HIGH);      // turn on the column (LED)
      delay(2000);   
      for (int i = 0; i < 8; i++) {
        digitalWrite(row[i], HIGH);   // turn off all rows
        digitalWrite(col[i], LOW);  // turn off all columns (LEDs)
      }
    }
  }
}
