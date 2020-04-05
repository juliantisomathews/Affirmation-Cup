
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

const int sensor = A0;
const int button =  11;

int threshhold = 550;
int choose = 0;


String texts[10] = {"A beautiful, smart, and loving person will be coming into your life.",
"A golden egg of opportunity falls into your lap this month.",
"A new perspective will come with the new year.",
"A feather in the hand is better than a bird in the air.",
"All the troubles you have will pass away very quickly.",
"All the effort you are making will ultimately pay off.",
"Good news will come to you by mail."
"Believe in yourself and others will too.",
"A golden egg of opportunity falls into your lap this month.",
"Stand tall. Do not look down upon yourself."};

Adafruit_SSD1306 display(OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(button,INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize display
  display.clearDisplay(); // clear display before each start
  delay(100);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensor);
      Serial.print(sensorVal);
      Serial.print("\t");
      Serial.print(digitalRead(button));
  if (digitalRead(button) == 1 && sensorVal<threshhold){
     choose = random(10);
     Serial.print("\t");
    }
  Serial.print("\t");
  Serial.println(choose);

  if (sensorVal>threshhold){
  displayScreen(choose);
  }
  else{
    display.clearDisplay(); // clear display before each start
    display.display();
    }

//  delay(2000);
  
}

void displayScreen(int c){
  display.clearDisplay(); // clear display before each start
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(texts[c]);

//  display.println("sensor value:");
//  int sensorVal = analogRead(sensor);
//    display.println(sensorVal);
//    Serial.println(sensorVal);
//  display.println(texts[choose]);
  display.display();
}
