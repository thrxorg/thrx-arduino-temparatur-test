// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef temper_test_H_
#define temper_test_H_
#include "Arduino.h"
//add your includes for the project temper_test here
#include <OneWire.h>
#include <DallasTemperature.h>


//end of add your includes here

#define ONE_WIRE_BUS 2 /* Digitalport Pin 2 definieren */
OneWire ds(ONE_WIRE_BUS);
DallasTemperature sensors(&ds);/* Dallas Temperature Library f�r Nutzung der oneWire Library vorbereiten */

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
void testDallasLib();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project temper_test here




//Do not add code below this line
#endif /* temper_test_H_ */
