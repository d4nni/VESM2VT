const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};
// tveggja dimension dálkar
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

int pixl[8][8];

void setup() {
  // put your setup code here, to run once:
  for (int pinni = 0; pinni < 8; pinni++){
    pinMode(col[pinni], INPUT);
    pinMode(row[pinni], INPUT);
    digitalWrite(col[pinni], LOW);
    digitalWrite(row[pinni], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x = 0; x < 8; x++) {
    for(int y = 0; y < 8; y++) {
      digitalWrite(row[x], LOW);
      digitalWrite(col[y],HIGH);
    }
  }
}
