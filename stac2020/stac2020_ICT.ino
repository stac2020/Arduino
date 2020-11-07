/*
- Project: 스택2020 척척추추
- 담당자: 양준혁
- 최종 수정일: 2020.11.03
*/

//헤더파일 선언부
#include <ArduinoBLE.h>
#include <Arduino_LSM6DS3.h>

float acX, acY, acZ, gyX, gyY, gyZ; //가속도, 각속도 값을 저장하는 변수

double angle = 0, deg; //각도, deg data

double dgyX; //accData

//millis
int c_millis = 0;
int p_millis = 0;

void setup() {
  Serial.begin(9600); //pc와 연결
  if(!IMU.begin()) { //LSM6DS3센서 시작
    Serial.println("LSM6DS3센서 오류!");
    while (1);
  }
}

void loop() {
  calAngle();
}

void calAngle(){
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(acX, acY, acZ);
    IMU.readGyroscope(gyX, gyY, gyZ);
    
    //각도 계산
    deg = atan2(acX, acZ) * 180 /PI;
    dgyX = gyY / 131. ;
    angle = (0.95 * (angle + (dgyX * 0.001))) + (0.05 * deg);

    //출력
    Serial.println(angle);
    workingVibration(); //진동 함수 호출
  }
}
