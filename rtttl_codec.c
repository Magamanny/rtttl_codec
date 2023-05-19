#include "rtttl_codec.h"
#include <string.h>
// https://www.srtware.com/index.php?/ringtones/rtttlformat.php
const char song0[] = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
const char song1[] = "Imperial:d=4,o=5,b=100:e,e,e,8c,16p,16g,e,8c,16p,16g,e,p,b,b,b,8c6,16p,16g,d#,8c,16p,16g,e,8p";
const char song2[] = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
const char song3[] = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
const char song4[] = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
const char song5[] = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
const char song6[] = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
const char song7[] = "Gadget:d=16,o=5,b=50:32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,32d#,32f,32f#,32g#,a#,d#6,4d6,32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,8d#";
const char song8[] = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
const char song9[] = "smb:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16d#6,8p,16d6,8p,16c6";
const int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

static void rtttl_song(int);
static void rtttl_play(const char p[], int len);
static int isdigit(char c);
static void rtttl_inint();

rtttl_codec_st rtttl_s = {
  .init = rtttl_inint,
  .play = rtttl_play,
  .song = rtttl_song
};

static void rtttl_inint()
{
  // inital checking
}

static int isdigit(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
static void rtttl_song(int x)
{
  switch(x)
  {
  case 0:
    rtttl_s.play(song0,strlen(song0));
    break;
  case 1:
    rtttl_s.play(song1,strlen(song1));
    break;
  case 2:
    rtttl_s.play(song2,strlen(song2));
    break;
  case 3:
    rtttl_s.play(song3,strlen(song3));
    break;
  case 4:
    rtttl_s.play(song4,strlen(song4));
    break;
  case 5:
    rtttl_s.play(song5,strlen(song5));
    break;
  case 6:
    rtttl_s.play(song6,strlen(song6));
    break;
  case 7:
    rtttl_s.play(song7,strlen(song7));
    break;
  case 8:
    rtttl_s.play(song8,strlen(song8));
    break;
  case 9:
    rtttl_s.play(song9,strlen(song9));
    break;
  }
}
static void rtttl_play(const char p[], int len)
{
  // Absolutely no error checking in here
  uint8_t default_dur = 4;
  uint8_t default_oct = 6;
  int bpm = 63;
  int num=0;
  long wholenote;
  long duration;
  uint8_t note;
  uint8_t scale;
  char name[15]={0}; // max 10 name
  int index=0;
  index=0;
  // assertion, TODO
  if(rtttl_s.delayms==0 || rtttl_s.tone_start==0 || rtttl_s.tone_stop==0)
  {
    return;
  }
  for(int i=0;i<15;i++,index++)
  {
    if(p[index]==':')
    {
      break;
    }
    else
    {
      name[i] = p[index];
    }
  } // end of for
  index++; // skip :
  if(p[index]=='d')
  {
    index++;index++; // skip d=
    num=0;
    for(int i=0;i<3;i++,index++)
    {
      if(p[index]==',')
      {
        break;
      }
      num = num*10 + (p[index] - '0');
    }
    index++; // skip 
    if(num > 0) default_dur = num;
  }
  // get default octave
  if(p[index] == 'o')
  {
    index++; index++;              // skip "o="
    num = p[index++] - '0';
    if(num >= 3 && num <=7) default_oct = num;
    index++;                   // skip comma
  }
  // get BPM
  if(p[index] == 'b')
  {
    index++; index++;              // skip "b="
    num = 0;
    for(int i=0;i<3;i++)
    {
      if(p[index]==':')
      {
        break;
      }
      num = (num * 10) + (p[index++] - '0');
    }
    index++;
    bpm = num;
  }
  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)
  // play loop
  for(;index<len;index++)
  {
    // first, get note duration, if available
    num=0;
    for(int i=0;i<2;i++)
    {
      if(isdigit(p[index]))
      {
        num = (num * 10) + (p[index++] - '0');
      }
      else
      {
        break;
      }
    }
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after
    // now get the note
    note = 0;
    switch(p[index])
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
        break;
      default:
        note = 0;
    }
    index++;
    // now, get optional '#' sharp
    if(p[index] == '#')
    {
      note++;
      index++;
    }
    // now, get optional '.' dotted note
    if(p[index] == '.')
    {
      duration += duration/2;
      index++;
    }
    // now, get scale
    // now, get scale
    if(isdigit(p[index]))
    {
      scale = p[index] - '0';
      index++;
    }
    else
    {
      scale = default_oct;
    }
    scale += OCTAVE_OFFSET;
    // now play the note
    if(note)
    {
      rtttl_s.tone_start(notes[(scale - 4) * 12 + note]);
      rtttl_s.delayms(duration);
      rtttl_s.tone_stop();
      //buzzer.frequency = ();
      //pwm_init(buzzer);
      //pwm_set(buzzer, 50);
      //vTaskDelay(pdMS_TO_TICKS(duration));
      //pwm_set(buzzer, 0);
    }
    else
    {
      rtttl_s.delayms(duration);
    }
  }
}