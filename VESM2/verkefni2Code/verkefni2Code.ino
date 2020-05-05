#define ROW_1 2
#define ROW_2 7
#define ROW_3 A5
#define ROW_4 5
#define ROW_5 13
#define ROW_6 A4
#define ROW_7 12
#define ROW_8 A2

#define COL_1 6
#define COL_2 11
#define COL_3 10
#define COL_4 3
#define COL_5 A3
#define COL_6 4
#define COL_7 8
#define COL_8 9

const byte rows[] = {
    // 2    7      A5     5      13     A4     12     A2
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  // 6    11     10     3      A3     4      8      9
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

float timeCount = 0;

void setup() 
{   
    // fá alla pinna virka
    // Setja alla pinna á OUTPUT
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
}

void loop() {
// loopan gengur aftur og aftur, þrjár virknir endurtakast og er smá delay milli 
fyrstaVirkni();
delay(100);
onnurVirkni();
delay(100);
thridjaVirkni();
}

// fyrsta virknin er búin til
//Fyrsta virknin gengur út á að birta eina röð í einu yfir borðið og svo slökknar alltaf eitt í einu þangað til ekkert sést lengur
void fyrstaVirkni() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    delay(100);
    for (byte x = 0; x < 8; x++) {
      digitalWrite(col[x], HIGH);
      delay(100);

      digitalWrite(col[x], LOW);
    }
  digitalWrite(rows[i], HIGH);
}
}

//Önnur virkni er að gera nákvæmlega öfugt við fyrstu virkni þannig að ljósin byrja að kvikna eitt af einu hinum megin á borðinu og endar á öllum ljósum í röðinni kveikt
//Önnur virknin búin til
void onnurVirkni() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    delay(100);
    for (byte x = 0; x < 8; x++) {
      digitalWrite(col[x], HIGH);
      delay(100);
    digitalWrite(col[x], LOW);
    }
}
}

// þriðja virknin er bara að allur skjárinn lýsist upp
//Þriðja virknin búin til
void thridjaVirkni() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    delay(100);
    for (byte x = 0; x < 8; x++) {
      digitalWrite(col[x], HIGH);
      delay(10);  
    }
}
}
