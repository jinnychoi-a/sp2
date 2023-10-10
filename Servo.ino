// https://wikidocs.net/30882 
#include<Servo.h> //Servo 라이브러리를 추가 
Servo servo;      //Servo 클래스로 servo 객체 생성

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);     //멤버함수인 attach : 핀설정
  // 아두이노의 디지털 9번핀을 서보모터 제어에 사용  
}

void loop() {
  // 서보 모터의 각도를 0~190도까지 변경하여 동작
  for (int angle=0; angle<180; angle++) {
    servo.write(angle);
    delay(100);
  }

}
