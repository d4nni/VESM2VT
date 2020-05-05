int vrx = A0; // Stýripinni X
int vry = A1; // Stýripinni Y

// Halda utan um stöðuna á led ljósunum í fylki (svipað og list í python)
// 0 slökkt er á led
// 1 kveikt á led þegar það er fært (cursor eða bendill)
// 2 kveikt á led af því að það hefur verið fest
// upphafsstaða: Slökkt á öllum nema því sem er lengst til vinstri
int ljosastada[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // staðsetning í fylkinu

const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

int pixels[8][8];
// cursor
int x = 0;
int y = 0;


void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) low to ensure that the LEDS are off:
    digitalWrite(col[thisPin], LOW);
    digitalWrite(row[thisPin], HIGH);
  }

  for (int x = 0; x  < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = LOW;
    }
  }
}

void loop() {
  pixels[x][y] = LOW;
  
  int x = 7 - map(analogRead(vrx),0,1023,0,7); // lesa frá stýripinna
  int y = map(analogRead(vry),0,1023,0,7); // lesa frá stýripinna
  
  if(x < 300) { // ef stýripinna er ýtt til vinstri 
    if(pixels[x][y] > 0) { // ef bendill er ekki staddur lengst til vinstri
      if(ljosastada[pixels[x][y]] != 2) { // ef ekki er búið að festa ljósið þar sem bendillinn er
        ljosastada[pixels[x][y]] = 0; // slökkva ljósið þar sem bendillinn er núna
      }
      pixels[x][y]--; // færa bendil um eitt sæti til vinstri
      if(ljosastada[pixels[x][y]] != 2) { // ef ekki er búið að festa ljósið þar sem bendillinn er
        ljosastada[pixels[x][y]] = 1; // kveikja ljósið þar sem bendillinn er núna
      }
    }
  }
  if(x > 530) { // ef stýripinna er ýtt til vinstri 
    if(pixels[x][y] < 7) { // ef bendill er ekki staddur lengst til vinstri
      if(ljosastada[pixels[x][y]] != 2) { // ef ekki er búið að festa ljósið þar sem bendillinn er
        ljosastada[pixels[x][y]] = 0; // slökkva ljósið þar sem bendillinn er núna
      }
      pixels[x][y]++; // færa bendil um eitt sæti til hægri
      if(ljosastada[pixels[x][y]] != 2) { // ef ekki er búið að festa ljósið þar sem bendillinn er
        ljosastada[pixels[x][y]] = 1; // kveikja ljósið þar sem bendillinn er núna
      }
    }
  }
  
  if(y > 800) { // ef stýripinna er ýtt upp
    ljosastada[pixels[x][y]] = 2; // "Festa" ljósið
  }
  if(y < 200) { // ef sýripinna er ýtt niður
    ljosastada[pixels[x][y]] = 1; // kveikt af því að hér er bendillinn
  }
  
  // Skrifa út ljósastöðu
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    // take the row pin (anode) low:
     if(ljosastada[thisRow] == 0) {
      digitalWrite(thisRow + 2, LOW); // i + 2, LED eru í pinnum 2 til og með 9
    }
    // iterate over the cols (cathodes):
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the row is LOW and the col is HIGH,
      // the LED where they meet turns on:
      digitalWrite(col[thisCol], thisPixel);
      // turn the pixel off:
      digitalWrite(col[thisCol], LOW);
    }
    // take the row pin high to turn off the whole row:
    digitalWrite(row[thisRow], HIGH);
  }
   // smá delay til að bendill hreyfist ekki of hratt
}
