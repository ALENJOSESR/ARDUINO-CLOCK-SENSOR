#include <MyRealTimeClock.h>

MyRealTimeClock myRTC(6, 7, 8); // Assign Digital Pins
int dayofMonth;
int Month;
int Year;
int Hours;
int Minutes;
int Seconds;




void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);


  /* To set the current time and date in specific format
    | Second 00 | Minute 59 | Hour 10 | Day 12 |  Month 07 | Year 2015 |
  */
  myRTC.setDS1302Time(00, 8, 9, 15 , 10, 10, 2019);
  myRTC.updateTime();
}

void loop() {
  

  // Allow the update of variables for time / accessing the individual element.

  myRTC.updateTime();


  int dayofMonth = (myRTC.dayofmonth); // Element 1

  int Month(myRTC.month); // Element 2

  int Year = (myRTC.year); // Element 3

  int Hours = (myRTC.hours); // Element 4

  int Minutes = (myRTC.minutes); // Element 5

  int Seconds = (myRTC.seconds); // Element 6


  if (digitalRead(2) == LOW)
  {
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("CAPRURED");
    Serial.println("Current Date / Time: ");
    Serial.print(dayofMonth);
    Serial.print("/");
    Serial.print(Month);
    Serial.print("/");
    Serial.print(Year);
    Serial.print(" ");
    Serial.print(Hours);
    Serial.print(":");
    Serial.print(Minutes);
    Serial.print(":");
    Serial.print(Seconds);

  }

  delay(1000);



}
