//Set pin connections of 8x8 matrix LED display
const int ROW_1_PIN = 9;
const int ROW_2_PIN = 8;
const int ROW_3_PIN = 7;
const int ROW_4_PIN = 6;
const int ROW_5_PIN = 5;
const int ROW_6_PIN = 4;
const int ROW_7_PIN = 3;
const int ROW_8_PIN = 2;

const int COLUMN_1_PIN = 19;
const int COLUMN_2_PIN = 18;
const int COLUMN_3_PIN = 17;
const int COLUMN_4_PIN = 16;
const int COLUMN_5_PIN = 15;
const int COLUMN_6_PIN = 14;
const int COLUMN_7_PIN = 13;
const int COLUMN_8_PIN = 12;

//identifying letter bits
byte Shape[][8] ={
{
  0b00000000,
  0b00000000,
  0b01000100,
  0b01101100,
  0b01010100,
  0b01000100,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b01000100,
  0b01000100,
  0b01000100,
  0b01111100,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b01110000,
  0b01000000,
  0b01000000,
  0b01110000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00110000,
  0b00000000,
  0b00110000,
  0b00110000,
  0b00110000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b01111000,
  0b01000000,
  0b01111000,
  0b01000000,
  0b01000000,
  0b00000000
}};

void setup() {
  // Set pin modes
  pinMode(ROW_1_PIN, OUTPUT);
  pinMode(ROW_2_PIN, OUTPUT);
  pinMode(ROW_3_PIN, OUTPUT);
  pinMode(ROW_4_PIN, OUTPUT);
  pinMode(ROW_5_PIN, OUTPUT);
  pinMode(ROW_6_PIN, OUTPUT);
  pinMode(ROW_7_PIN, OUTPUT);
  pinMode(ROW_8_PIN, OUTPUT);  
  pinMode(COLUMN_1_PIN, OUTPUT);
  pinMode(COLUMN_2_PIN, OUTPUT);
  pinMode(COLUMN_3_PIN, OUTPUT);
  pinMode(COLUMN_4_PIN, OUTPUT);
  pinMode(COLUMN_5_PIN, OUTPUT);
  pinMode(COLUMN_6_PIN, OUTPUT);
  pinMode(COLUMN_7_PIN, OUTPUT);
  pinMode(COLUMN_8_PIN, OUTPUT);  
  
  clearDisplay();  //Clean led screen
}
void loop() {
  
  // for  letter M
  drawShape(0,1000);
  clearDisplay();
  delay(100); // Wait 0.5 s

  // for letter U
  drawShape(1,1000);
  clearDisplay();  //Clean led screen
  delay(500); //  Wait 0.5 s

  // for letter C
  drawShape(2,1000);
  clearDisplay();
  delay(500); 

  //for letter I
  drawShape(3,1000);
  clearDisplay();
  delay(500); 

  //for letter F
  drawShape(4,1000);
  clearDisplay();
  delay(500); 
}

void clearDisplay() {
  for (int row = 2; row <= 9; row++) {
    digitalWrite(row, HIGH);
  }  for (int col = 12; col <= 19; col++) {
    digitalWrite(col, LOW);     // turn off
  }
}

void drawShape(uint8_t index, unsigned long time) {
   unsigned long startTime = millis();           // determining  the current time
   while (millis() - startTime < time){          // measuring time
    for (int row = 0; row < 8; row++) {
    digitalWrite(row + 2, LOW);    for (int col = 0; col < 8; col++) {
      digitalWrite(col + 12, bitRead(Shape[index][7 - row], col));
    }    delay(1);
    digitalWrite(row + 2, HIGH);
   }
 }
}
