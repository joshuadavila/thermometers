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

// custom inverse "1" character map
byte customChar1[8] = {
  0b11111,
  0b11011,
  0b10011,
  0b11011,
  0b11011,
  0b11011,
  0b10001,
  0b11111
};

// custom inverse "2" character map
byte customChar2[8] = {
  0b11111,
  0b10001,
  0b11101,
  0b10001,
  0b10111,
  0b10001,
  0b11111,
  0b11111
};

// custom inverse "3" character map
byte customChar3[8] = {
  0b11111,
  0b10001,
  0b11101,
  0b10001,
  0b11101,
  0b10001,
  0b11111,
  0b11111
};

// custom inverse "4" character map
byte customChar4[8] = {
  0b11111,
  0b10101,
  0b10101,
  0b10001,
  0b11101,
  0b11101,
  0b11111,
  0b11111
};

// custom inverse "ºc" character map
byte customCharGrades[8] = {
  0b11000,
  0b11000,
  0b00000,
  0b00111,
  0b00100,
  0b00100,
  0b00111,
  0b00000
};

void setup() {
  
  lcd.begin(16,2);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customCharGrades); 
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
lcd.setCursor(0, 0);
lcd.write(1);
lcd.setCursor(1, 0);
if(temp1==-127.00){
  lcd.print("       ");
}
else  {
      lcd.print(temp1);
      lcd.setCursor(7,0);
      lcd.write(5);
      }
      
// prints second sensor
lcd.setCursor(8, 0);
lcd.write(2);
lcd.setCursor(9, 0);
if(temp2==-127.00){
  lcd.print("       ");
}
else {
      lcd.print(temp2);
      lcd.setCursor(15,0);
      lcd.write(5);
      }

    
// prints third sensor
lcd.setCursor(0, 1);
lcd.write(3);
lcd.setCursor(1, 1);
if(temp3==-127.00){
  lcd.print("       ");
}
else {
      lcd.print(temp3);
      lcd.setCursor(7,1);
      lcd.write(5);
      }
      
// prints fourth sensor
lcd.setCursor(8, 1);
lcd.write(4);
lcd.setCursor(9, 1);
if(temp4==-127.00){
  lcd.print("       ");
}
else {
      lcd.print(temp4);
      lcd.setCursor(15,1);
      lcd.write(5);
      }

}
