#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int lm35Pin = A2;
int flag = 0;
int red = 9; // red led, pinMode 9
int green = 10; // green led, pinMode 10
int blue = 11; // blue led, pinMode 11

void setup() {
  analogReference(INTERNAL); 
  Serial.begin(9600); // 시리얼 모니터
  
  // lcd 초기설정
  lcd.init(); 
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float temp = analogRead(lm35Pin) / 9.31;

  Serial.println(temp);
  delay(1000);
  
  if( 18 >= temp ){ // 실내온도가 18도 이하이면
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 255); // BLUE LED 켜기
  }
  else if(18 < temp < 20 ){ // 실내온도가 18도 초과 20도 이하이면
    analogWrite(red, 0);
    analogWrite(green, 255); // GREEN LED 켜기
    analogWrite(blue, 0);
  }
  else if( temp >= 20 ){ // 실내온도가 20도 이상이면
    analogWrite(red, 255); // RED LED 켜기
    analogWrite(green, 0);
    analogWrite(blue, 0); 
  }
  
  lcd.setCursor(0,0); 
  lcd.print("Home temp : ");
  lcd.print(temp); // LCD에 실내온도 출력하기
  lcd.setCursor(0,1);
  lcd.print("Sensing...");
}
