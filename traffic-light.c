#define MY_PORT *(unsigned char*)0x2B
#define MY_PORT_DDR *(unsigned char*)0x2A
#define GREEN_1 (1 << 2)
#define GREEN_1_ON MY_PORT |= GREEN_1
#define GREEN_1_OFF MY_PORT &= ~GREEN_1
#define YELLOW_1 (1 << 3)
#define YELLOW_1_ON MY_PORT |= YELLOW_1
#define YELLOW_1_OFF MY_PORT &= ~YELLOW_1
#define RED_1 (1 << 4)
#define RED_1_ON MY_PORT |= RED_1
#define RED_1_OFF MY_PORT &= ~RED_1
#define GREEN_2 (1 << 5)
#define GREEN_2_ON MY_PORT |= GREEN_2
#define GREEN_2_OFF MY_PORT &= ~GREEN_2
#define YELLOW_2 (1 << 6)
#define YELLOW_2_ON MY_PORT |= YELLOW_2
#define YELLOW_2_OFF MY_PORT &= ~YELLOW_2
#define RED_2 (1 << 7)
#define RED_2_ON MY_PORT |= RED_2
#define RED_2_OFF MY_PORT &= ~RED_2
#define LONG_PAUSE 1000000
#define SHORT_PAUSE 200000
void setup() {
  //sets ports to output
  MY_PORT_DDR |= (GREEN_1 | YELLOW_1 | RED_1 | GREEN_2 | YELLOW_2 | RED_2);
}

void pause(long duration) {
  volatile long pause = 0;
  for(pause = 0; pause < duration; pause++) {
    pause=pause;
  }  
}

// the loop function runs over and over again forever
void loop() {
  //N 
  RED_1_ON;
  //S 
  GREEN_2_ON;
  pause(LONG_PAUSE);
  //N
  YELLOW_1_ON;
  //S
  YELLOW_2_ON;
  GREEN_2_OFF;
  pause(SHORT_PAUSE);
  //N
  RED_1_OFF;
  YELLOW_1_OFF;
  GREEN_1_ON;
  //S
  YELLOW_2_OFF;
  RED_2_ON;
  pause(LONG_PAUSE);
  //N
  YELLOW_1_ON;
  GREEN_1_OFF;
  //S
  YELLOW_2_ON;
  pause(SHORT_PAUSE);
  //N
  YELLOW_1_OFF;
  //S
  RED_2_OFF;
  YELLOW_2_OFF;
}
