#include "SevSeg.h"
SevSeg sevseg; 

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {7, 6, 4, 2, 1, 9, 10, 5};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    for(int i = 0; i < 10; i++){
        sevseg.setNumber(i, i%2);
        delay(1000);
        sevseg.refreshDisplay(); 
        }
}
