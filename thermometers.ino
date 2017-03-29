#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

OneWire ourwire1(65);
OneWire ourwire2(64);
OneWire ourwire3(63);
OneWire ourwire4(62);
LiquidCrystal lcd(54, 55, 56, 57, 58, 59);

DallasTemperature sensor1(&ourwire1);
DallasTemperature sensor2(&ourwire2);
DallasTemperature sensor3(&ourwire3);
DallasTemperature sensor4(&ourwire4);

void setup() {
  lcd.begin(16,2);
  sensor1.begin();
  sensor2.begin();
  sensor3.begin();
  sensor4.begin();
  
}

void loop() {

sensor1.requestTemperatures();
float temp1=sensor1.getTempCByIndex(0);

sensor2.requestTemperatures();
float temp2=sensor2.getTempCByIndex(0);

sensor3.requestTemperatures();
float temp3=sensor3.getTempCByIndex(0);

sensor4.requestTemperatures();
float temp4=sensor4.getTempCByIndex(0);

// prints first sensor
lcd.setCursor(1, 0);
if(temp1==-127.00)lcd.print("-----");
else lcd.print(temp1);

// prints second sensor
lcd.setCursor(10, 0);
if(temp2==-127.00)lcd.print("-----");
else lcd.print(temp2);
    
// prints third sensor
lcd.setCursor(1, 1);
if(temp3==-127.00)lcd.print("-----");
else lcd.print(temp3);

// prints fourth sensor
lcd.setCursor(10, 1);
if(temp4==-127.00)lcd.print("-----");
else lcd.print(temp4);

}
