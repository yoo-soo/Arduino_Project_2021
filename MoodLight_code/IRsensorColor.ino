#include <IRremote.hpp> // 적외선 리모컨 라이브러리 
IRrecv irrecv(7); // IR 리모컨을 사용하기 위한 7번핀 사용 선언
decode_results results; // IR 리모컨으로부터 받은 신호값

// FF30CF FF18E7 FF7A85 : 1 2 3
// FF10EF FF38C7 FF5AA5 : 4 5 6
// FF42BD FF4AB5 FF52AD : 7 8 9
// FFE01F FFA857 : - +

int red = 9; // red led, pinMode 9
int green = 10; // green led, pinMode 10
int blue = 11; // blue led, pinMode 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // 시리얼 모니터
  irrecv.enableIRIn(); // 리모컨 수신
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)==true){ // 리모컨으로 받은 신호가 있으면
    //Serial.println(results.value, HEX); // 받은 신호를 시리얼 모니터에 출력
    switch (results.value){
      case 0xFF30CF: analogWrite(red, 0); // 1번 버튼 : 빨간색 조명
                     analogWrite(green, 255);
                     analogWrite(blue, 255); break;
                     //Serial.println("1"); break;
      case 0xFF18E7: analogWrite(red, 0); // 2번 버튼 : 분홍색 조명
                     analogWrite(green, 150);
                     analogWrite(blue, 75); break;
                     //Serial.println("2"); break;
      case 0xFF7A85: analogWrite(red, 0); // 3번 버튼 : 주황색 조명
                     analogWrite(green, 115);
                     analogWrite(blue, 255); break;
                     //Serial.println("3"); break;
      case 0xFF10EF: analogWrite(red, 0); // 4번 버튼 : 노란색 조명
                     analogWrite(green, 0);
                     analogWrite(blue, 255); break;
                     //Serial.println("4"); break;
      case 0xFF38C7: analogWrite(red, 255); // 5번 버튼 : 초록색 조명
                     analogWrite(green, 0);
                     analogWrite(blue, 255); break;
                     //Serial.println("5"); break;
      case 0xFF5AA5: analogWrite(red, 128); // 6번 버튼 : 청록색 조명
                     analogWrite(green, 0);
                     analogWrite(blue, 255); break;
                     //Serial.println("6"); break;
      case 0xFF42BD: analogWrite(red, 255); // 7번 버튼 : 파란색 조명
                     analogWrite(green, 255);
                     analogWrite(blue, 0); break;
                     //Serial.println("7"); break;
      case 0xFF4AB5: analogWrite(red, 127); // 8번 버튼 : 보라색 조명
                     analogWrite(green, 255);
                     analogWrite(blue, 127); break;
                     //Serial.println("8"); break;
      case 0xFF52AD: analogWrite(red, 0); // 9번 버튼 : 흰색 조명
                     analogWrite(green, 0);
                     analogWrite(blue, 0); break;
                     //Serial.println("9"); break;
                     
      case 0xFF6897: analogWrite(red, 255); // 0번 버튼 : 조명 끄기 
                     analogWrite(green, 255);
                     analogWrite(blue, 255); break;
                     //Serial.println("0"); break;
    }
    irrecv.resume(); // 다음 신호 수신
  }
}
