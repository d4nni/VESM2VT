/*
  Row-Column Scanning an 8x8 LED matrix with X-Y input

  This example controls an 8x8 LED matrix using two analog inputs.

  This example works for the Lumex LDM-24488NI Matrix. See
  http://sigma.octopart.com/140413/datasheet/Lumex-LDM-24488NI.pdf
  for the pin connections.

  For other LED cathode column matrixes, you should only need to change the pin
  numbers in the row[] and column[] arrays.

  rows are the anodes
  cols are the cathodes
  ---------

  Pin numbers:
  Matrix:
  - digital pins 2 through 13,
  - analog pins 2 through 5 used as digital 16 through 19
  Potentiometers:
  - center pins are attached to analog pins 0 and 1, respectively
  - side pins attached to +5V and ground, respectively

  created 27 May 2009
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/RowColumnScanning

  see also http://www.tigoe.net/pcomp/code/category/arduinowiring for more
*/

// 2-dimensional array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

// 2-dimensional array of pixels:
int pixels[8][8];

// cursor position:
int x = 5;
int y = 5;
unsigned long time_now = 0;


void setup() {
  // initialize the I/O pins as outputs iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) low to ensure that the LEDS are off:
    digitalWrite(col[thisPin], LOW);
    digitalWrite(row[thisPin], HIGH);
  }

  // initialize the pixel matrix:
  for (int x = 0; x  < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = LOW;
    }
  }
}

void loop() {
  time_now = millis();
  // read input:
    readSensors();
  while(millis() < time_now + 10){
    refreshScreen();
  }
  // draw the screen:
}

void readSensors() {
  // turn off the last position:
  
  // read the joystick for X and Y values:
  x = map(analogRead(A0), 0, 1023, 0, 7);
  y = 7 - map(analogRead(A1), 0, 1023, 0, 7);
  // set the new pixel position high so that the LED will turn on in the next
  // screen refresh:
  pixels[x][y] = HIGH;
}

void refreshScreen() {
  // iterate over the rows (anodes):
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    // take the row pin (anode) low:
    digitalWrite(row[thisRow], LOW);
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
}
