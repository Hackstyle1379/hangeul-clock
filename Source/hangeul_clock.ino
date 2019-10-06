/*
제목 : 한글 시계 만들기
내용 : 오렌지보드를 이용해 5분 단위로 시간을 한글로 표현하는 한글 시계 만들어보기

이 소스코드는 kocoafab에서 작성하였습니다. 
소스코드 배포시에는 출처를 남겨주시기 바랍니다. 

E mail : contact@kocoa.or.kr
*/

#include <Wire.h>
#include <avr/power.h>
#include "Time.h"
#include "DS1307RTC.h"
#include "Adafruit_NeoPixel.h"


#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, PIN, NEO_GRB + NEO_KHZ800);
uint32_t color = strip.Color(232, 101, 12);

void hoursFilter(int hours, int minutes) {
  if (hours == 0 && minutes == 0) { //00:00
    strip.setPixelColor(24, color);
    strip.setPixelColor(35, color);
  }
  else if (hours == 12 && minutes == 0) {
	strip.setPixelColor(24, color);
    strip.setPixelColor(30, color); //정오 표시
	strip.setPixelColor(14, color);
    strip.setPixelColor(16, color);
    strip.setPixelColor(17, color); //12:00
  }
  else if (hours == 1 || hours == 13) {
    strip.setPixelColor(0, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 2 || hours == 14) {
    strip.setPixelColor(1, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 3 || hours == 15) {
    strip.setPixelColor(2, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 4 || hours == 16) {
    strip.setPixelColor(3, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 5 || hours == 17) {
    strip.setPixelColor(4, color);
    strip.setPixelColor(5, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 6 || hours == 18) {
    strip.setPixelColor(11, color);
    strip.setPixelColor(10, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 7 || hours == 19) {
    strip.setPixelColor(9, color);
    strip.setPixelColor(8, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 8 || hours == 20) {
    strip.setPixelColor(7, color);
    strip.setPixelColor(6, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 9 || hours == 21) {
    strip.setPixelColor(12, color);
    strip.setPixelColor(13, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 10 || hours == 22) {
    strip.setPixelColor(14, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 11 || hours == 23) {
    strip.setPixelColor(14, color);
    strip.setPixelColor(15, color);
    strip.setPixelColor(17, color);
  }
  else if (hours == 12 || hours == 24) {
    if (minutes > 0) {
	  strip.setPixelColor(23, color);
	  strip.setPixelColor(24, color); //자정 표시
      strip.setPixelColor(14, color);
      strip.setPixelColor(16, color);
      strip.setPixelColor(17, color);
    }
  }
  else ;
}


void minutesFilter(int minutes) {
	strip.setPixelColor(30, color);
  if (minutes==1 && minutes <= 10) {
      if (minutes==1){
        strip.setPixelColor(25, color);
      }
      else if (minutes==2){
        strip.setPixelColor(26, color);
      }
      else if (minutes==3){
        strip.setPixelColor(27, color);
      }
      else if (minutes==4){
        strip.setPixelColor(28, color);
      }
      else if (minutes==5){
        strip.setPixelColor(29, color);
      }
      else if (minutes==6){
        strip.setPixelColor(34, color);
      }
      else if (minutes==7){
        strip.setPixelColor(33, color);
      }
      else if (minutes==8){
        strip.setPixelColor(32, color);
      }
      else if (minutes==9){
        strip.setPixelColor(31, color);
      }
      else if (minutes==10){
        strip.setPixelColor(18, color);
      }
  }
  else if (minutes > 9 && minutes < 20) {
    strip.setPixelColor(18, color);
      if (minutes==11){
        strip.setPixelColor(25, color);
      }
      else if (minutes==12){
        strip.setPixelColor(26, color);
      }
      else if (minutes==13){
        strip.setPixelColor(27, color);
      }
      else if (minutes==14){
        strip.setPixelColor(28, color);
      }
      else if (minutes==15){
        strip.setPixelColor(29, color);
      }
      else if (minutes==16){
        strip.setPixelColor(34, color);
      }
      else if (minutes==17){
        strip.setPixelColor(33, color);
      }
      else if (minutes==18){
        strip.setPixelColor(32, color);
      }
      else if (minutes==19){
        strip.setPixelColor(31, color);
      }
      else if (minutes==20){
        strip.setPixelColor(22, color);
        strip.setPixelColor(18, color);
      }
  }
  else if (minutes > 19 && minutes < 30) {
    strip.setPixelColor(22, color);
    strip.setPixelColor(18, color);
      if (minutes==21){
        strip.setPixelColor(25, color);
      }
      else if (minutes==22){
        strip.setPixelColor(26, color);
      }
      else if (minutes==23){
        strip.setPixelColor(27, color);
      }
      else if (minutes==24){
        strip.setPixelColor(28, color);
      }
      else if (minutes==25){
        strip.setPixelColor(29, color);
      }
      else if (minutes==26){
        strip.setPixelColor(34, color);
      }
      else if (minutes==27){
        strip.setPixelColor(33, color);
      }
      else if (minutes==28){
        strip.setPixelColor(32, color);
      }
      else if (minutes==29){
        strip.setPixelColor(31, color);
      }
      else if (minutes==30){
        strip.setPixelColor(21, color);
        strip.setPixelColor(18, color);
      }
  }
  else if (minutes > 29 && minutes < 40) {
    strip.setPixelColor(21, color);
    strip.setPixelColor(18, color);
      if (minutes==31){
        strip.setPixelColor(25, color);
      }
      else if (minutes==32){
        strip.setPixelColor(26, color);
      }
      else if (minutes==33){
        strip.setPixelColor(27, color);
      }
      else if (minutes==34){
        strip.setPixelColor(28, color);
      }
      else if (minutes==35){
        strip.setPixelColor(29, color);
      }
      else if (minutes==36){
        strip.setPixelColor(34, color);
      }
      else if (minutes==37){
        strip.setPixelColor(33, color);
      }
      else if (minutes==38){
        strip.setPixelColor(32, color);
      }
      else if (minutes==39){
        strip.setPixelColor(31, color);
      }
      else if (minutes==40){
        strip.setPixelColor(20, color);
        strip.setPixelColor(18, color);
      }
  }
  else if (minutes > 39 && minutes < 50) {
    strip.setPixelColor(20, color);
    strip.setPixelColor(18, color);
      if (minutes==41){
        strip.setPixelColor(25, color);
      }
      else if (minutes==42){
        strip.setPixelColor(26, color);
      }
      else if (minutes==43){
        strip.setPixelColor(27, color);
      }
      else if (minutes==44){
        strip.setPixelColor(28, color);
      }
      else if (minutes==45){
        strip.setPixelColor(29, color);
      }
      else if (minutes==46){
        strip.setPixelColor(34, color);
      }
      else if (minutes==47){
        strip.setPixelColor(33, color);
      }
      else if (minutes==48){
        strip.setPixelColor(32, color);
      }
      else if (minutes==49){
        strip.setPixelColor(31, color);
      }
      else if (minutes==50){
        strip.setPixelColor(19, color);
        strip.setPixelColor(18, color);
      }
  }
  else if (minutes > 49 && minutes < 60) {
    strip.setPixelColor(19, color);
    strip.setPixelColor(18, color);
      if (minutes==51){
        strip.setPixelColor(25, color);
      }
      else if (minutes==52){
        strip.setPixelColor(26, color);
      }
      else if (minutes==53){
        strip.setPixelColor(27, color);
      }
      else if (minutes==54){
        strip.setPixelColor(28, color);
      }
      else if (minutes==55){
        strip.setPixelColor(29, color);
      }
      else if (minutes==56){
        strip.setPixelColor(34, color);
      }
      else if (minutes==57){
        strip.setPixelColor(33, color);
      }
      else if (minutes==58){
        strip.setPixelColor(32, color);
      }
      else if (minutes==59){
        strip.setPixelColor(31, color);
      }
  }
  else;
}

void ledReset() {
  for (int i = 0; i < 36; i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}

void setup() {
  Serial.begin(9600);
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show();
  while (!Serial) ; // 시리얼 통신이 가능할 때까지 대기한다.
  delay(200);
}

void loop() {
  tmElements_t tm; // RTC 객체 선언

  if (RTC.read(tm)) { //RTC 모듈로 부터 데이터가 들어온다면

    int hours = tm.Hour; //시(hour) 데이터를 hours 변수에 담는다.
    int minutes = tm.Minute; //분(minute) 데이터를 minutes 변수에 담는다.
    int seconds = tm.Second; //초(second) 데이터를 seconds 변수에 담는다.

    // 시, 분, 초 출력
    Serial.print(hours);
    Serial.print("\t");
    Serial.print(minutes);
    Serial.print("\t");
    Serial.println(seconds);


    // 1분에 한번씩 led 초기화
    if ((minutes % 1) == 0 && seconds == 0) {
      ledReset();
    }


    hoursFilter(hours, minutes); // 시(hour) LED 출력
    minutesFilter(minutes); // 분(minute) LED 출력
    strip.show();
  }
  else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    }
    else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}
