# 척척추추(척추 건강 웨어러블 서비스)
|<img src="https://user-images.githubusercontent.com/56965398/104684808-2462ac00-573d-11eb-983f-0110a6e5acf6.png"  width="100%">|<img src="https://user-images.githubusercontent.com/56965398/104684912-5116c380-573d-11eb-8fc0-ed2ca5f0f2e1.png"  width="100%">|
|---|---|

------------

## [👩‍👨‍팀원]
- 양준혁: 팀장, 임베디드 소프트웨어 개발
- 최우석: 임베디드 소프트웨어 개발
- 김경원: flutter 크로스 플랫폼 개발
- 김문모: flutter 크로스 플랫폼 개발

------------

## [👨‍💻개발 언어/프레임워크]   

|Flutter/Dart|<img src="https://user-images.githubusercontent.com/56965398/104685102-a6eb6b80-573d-11eb-80d8-4f8bcfe87f30.png"  width="40%">|
|---|---|
Arduino|<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104685229-e2863580-573d-11eb-9a9e-e88b9b097cef.png"  width="30%"><p/>|
C/C++|<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104685338-24af7700-573e-11eb-977c-3cdd761abbb7.png"  width="20%"><p/>||

------------    

## [🛠개발/디자인 툴]   

|Android Studio|<img src="https://user-images.githubusercontent.com/56965398/104442860-0419dc80-55d9-11eb-9e18-37877e1c49e1.png"  width="40%">|
|---|---|
|Arduino IDE|<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104685229-e2863580-573d-11eb-9a9e-e88b9b097cef.png"  width="40%"><p/>
|Figma|<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104545589-c4510480-566d-11eb-996f-6daec08e4917.png" width="40%"><p/>|
 

------------ 

## [✍ 개발 목표]
- ***"자세를 바르게 해라"***, ***"허리를 펴라"***, ***"목을 너무 앞으로 내밀지 말아라"***, ***"중간중간 움직이면서 공부를 해라"*** 우리는 성장을 하면서 이러한 이야기들을 많이 들으며 자라왔습니다.

- 많은 어른들이 자세에 대한 이야기를 많이 하는 이유는 잘못된 자세가 추후 ***척추 질환***을 불러오기 때문입니다. **컴퓨터**와 **스마트기기**의 보급에 따라 척추 질환 화자의 수가 해마다 늘어나고 있습니다.

- 그렇게 저희는 척추 건강 웨어러블 기기인 ***척척추추*** 디바이스와 어플리케이션을 만들게 되었습니다.   

![image](https://user-images.githubusercontent.com/56965398/104686434-8a9cfe00-5740-11eb-877f-ef0c01f6ef1d.png)   

------------
   
## [⛏ 프로젝트 설계 및 구현 내용]   
|UI/UX|![image](https://user-images.githubusercontent.com/56965398/104685947-8b816000-573f-11eb-97ea-3c8d00604eec.png)![image](https://user-images.githubusercontent.com/56965398/104686034-bff51c00-573f-11eb-964c-b6c5fadf52e7.png)|
|---|---|
|ClientDataBase|FireBase|
Connect|Bluetooth|
HardwareLanguage|C/C++|
HardwareFrameWork|Arduino|

- **구현 내용**
  1. **자세 교정 기능**  
    앉은자세의 각도가 올바른 각도를 벗어나 **올바르지 못한 각도가 지속**되면 스마트 벨트에서 진동으로 **사용자에게 알려**준다
    
  2. **스트레칭 기능**  
    앉은 시간을 계산해서 **일정 시간마다 스트레칭**을 하라는 알림을 사용자에게 보내준다. 또한 **어플리케이션을 통하여 스트레칭과 콘텐츠**를 함깨 추천해준다. 
    
  3. **올바른 자세 안내 기능**  
    앉은자ㅔ의 각도를 **실시간으로 올바른 자세와 비교**해서 보여준다.
    
  4. **자세 기록 기능**  
    앉은 자세의 각도를 기록해 **하루마다 평균값**을 내어 하루마다 **자세의 각도가 어떻게 되는지** 보여준다.   
    
------------   
    
## [🖥기능]  
   |<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104686564-c9cb4f00-5740-11eb-8bb2-3806f2637cd1.png"  width="60%"></p>|디바이스로 측정한 각도 데이터를 블루투스로 보내서 어플에서 시각적으로 보여준다.|
   |---|---|
   |<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104686619-ec5d6800-5740-11eb-9693-ec205592fdf0.png" width="60%"></p>|날마다 자세기록을 해서 자세가 좋아지는 모습을 시각적으로 보여줌|
   |<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104686683-0bf49080-5741-11eb-93d8-9d901453e952.png" width="60%"></p>|사용자가 스트레칭을 할 시간의 간격을 설정하고, 스트레칭을 유도한다. 그리고 사용자가 참고할 만한 스트레칭 컨텐츠를 추천해준다.|
   |<p align="center"><img src="https://user-images.githubusercontent.com/56965398/104686766-36dee480-5741-11eb-8eb6-638a0b4f9572.png" width="60%"></p>|다크 테마|   
    
------------   
    
## [👍기대효과]  
~~~
자세는 일찍 교정을 하지 않으면 나중에 많은 질환을 불러옵니다.
이러한 문제점을 파악한 여러 기업에서는 자세 교정과 관련된 의자나 스탠딩워크 등을 내세우고 있습니다.
하지만 척척추추의 경우 작은 디바이스와 휴대폰만 있으면 자세를 교정을 할 수 있기 때문에 
휴대성과 편리함을 중요시하는 바쁜 현대인들의 척추건강을 지킬 수 있습니다.
~~~   
    
------------   
    
## [🚴‍♂️ 발전 가능성(앞으로 수정할 부분)]
- 디자인 리펙토링
- 모바일 개발 언어와 프레임워크 교체
- ios 버전 개발
- MVVM 아키텍처 적용
- 하드웨어 리뉴얼
- 각도 측정 수정
- 각도 측정 필터 변경
위의 부분들을 수정/적용 하여 서비스를 출시하는 것이 저희 서비스의 최종 목표입니다.   
    
------------   
    
## [📖참고 문헌]  
- 핸드헬드 디바이스의 사용맥락에 따른 촉각 피드백의 사용자 민감도(한국미디어대학원대학교 뉴미디학부 노재인)
- 경추, 흉추 관절가동기법 및 전방 머리자세 교정운동이 머리자세와 목 통증에 미치는 영향(남서울대학교 대학원 김용민)
- EDM Medical News : 20대 '척추 주의보'
- 매일경제 : [올바른 자세] 의자에 110~135도 정도 기대 앉아라
- Arduino LSM6DS3 library 공식 
