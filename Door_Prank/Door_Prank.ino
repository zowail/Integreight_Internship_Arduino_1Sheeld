/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Ultrasonic.h>
#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD
#define trigger_pin 12
#define echo_pin 11

long ultrasonic ()
  {
    long duration,distance;
  digitalWrite(trigger_pin,LOW);
delayMicroseconds(2);
digitalWrite(trigger_pin,HIGH);
delayMicroseconds(10);
digitalWrite(trigger_pin,LOW);
duration=pulseIn(echo_pin,HIGH);
distance=(duration/2)/29.1;
  delay(100);
  //Serial.println(distance);
  return distance;
    }

void setup() {
 Serial.begin(9600);
 
  /* Start communication. */
  OneSheeld.begin();
pinMode(trigger_pin, OUTPUT);
pinMode(echo_pin,INPUT);
}

void loop() {
if(ultrasonic()<=25){
       /* Set the volume. */
       MusicPlayer.setVolume(10);
       /* Turn on the music. */
       MusicPlayer.play();
       /* Wait for 3000 ms. */
       OneSheeld.delay(3000);
        /* Turn off the music. */
      MusicPlayer.pause();
      /* Wait for 1500 ms. */
      OneSheeld.delay(1500);
            }
}
