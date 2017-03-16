/* Include 1Sheeld library. */
#include <OneSheeld.h>
#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD
void setup()
{
  Serial.begin(9600); 
 /* Start communication. */
  OneSheeld.begin();
}
void loop()
{
      int val;
      val=analogRead(0);//Connect the sensor to analog pin 0
      Serial.println(val,DEC);//
      if(val > 25)
      {
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
