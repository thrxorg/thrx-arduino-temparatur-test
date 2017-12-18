// Do not remove the include below
#include "temper_test.h"

int loopCnt = 0;
//The setup function is called once at startup of the sketch
void setup() {
	delay(5000);

	Serial.begin(9600);
	Serial.println("Temperatur Messprogramm");
	Serial.println("TWTemp 1.0 vom 14.06.2013");
	Serial.println("http://www.wenzlaff.de");
	sensors.begin();/* Inizialisieren der Dallas Temperature library */
	delay(1000);
	Serial.print("DeviceCount");
	delay(1000);
	Serial.println("-----" + sensors.getDeviceCount());
	delay(1000);

}

// The loop function is called in an endless loop
void loop() {
	if (++loopCnt >= 30){
		sensors.begin();
	}
	// reconfigure every 30th loop
	Serial.print(loopCnt);
	Serial.println(" -- getTemperatureSensors -----------------------------");
	delay(5000);
	testDallasLib();
}

void testDallasLib() {
	sensors.requestTemperatures();
	int count = sensors.getDeviceCount();
	Serial.print("-- getDeviceCount: ");
	Serial.println(count);
	for (int i = 0; i < count; i++) {
		byte addr[8];
		sensors.getAddress(addr,i);
		for (int i = 0; i < 8; i++) {
			Serial.print(addr[i], HEX);
		}
		Serial.print(" -- ");
		Serial.println( sensors.getTempC(addr));
		sensors.resetAlarmSearch();
	}
}
