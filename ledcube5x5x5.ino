/*
  LED Cube 5X5X5 Arduino Mega Code

  All Columns:
  *(1,1)______*(1,2)______*(1,3)______*(1,4)______*(1,5)
     |           |           |           |           |
     |           |           |           |           |
  *(2,1)______*(2,2)______*(2,3)______*(2,4)______*(2,5)
     |           |           |           |           |
     |           |           |           |           |
  *(3,1)______*(3,2)______*(3,3)______*(3,4)______*(3,5)
     |           |           |           |           |
     |           |           |           |           |
  *(4,1)______*(4,2)______*(4,3)______*(4,4)______*(4,5) 
     |           |           |           |           |
     |           |           |           |           |
  *(5,1)______*(5,2)______*(5,3)______*(5,4)______*(5,5) 

  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-24
  (1,2)-23
  (1,3)-22
  (1,4)-21
  (1,5)-20
  (2,1)-19
  (2,2)-18
  (2,3)-17
  (2,4)-16
  (2,5)-15
  (3,1)-14
  (3-2)-13
  (3-3)-12
  (3,4)-11
  (3,5)-10
  (4,1)-9
  (4,2)-8
  (4,3)-7
  (4,4)-6
  (4,5)-5
  (5,1)-4
  (5,2)-3
  (5,3)-2
  (5,4)-1
  (5,5)-0
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
  e-A4

*/

  //initializing and declaring led columns
  int column[25]={24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  //initializing and declaring led layers
  int layer[5]={A0,A1,A2,A3,A4};
  int time = 250;
 
  void setup()
  {
    //Setup all columns to Output 
    for(int i = 0; i<25; i++)
    {
    pinMode(column[i], OUTPUT);
    }
    
    //Setup all rows to Output
    for(int i = 0; i<5; i++)
    {
    pinMode(layer[i], OUTPUT);
    }
   
    //seeding random for random pattern
    randomSeed(analogRead(10));
  }

  void loop()
  {
  turnEverythingOff();
  flickerOn();
  turnEverythingOn();
  delay(time);
  turnOnAndOffAllByLayerUpAndDownNotTimed();
  newpattern();
  turnEverythingOn();
  layerstompUpAndDown();
  turnOnAndOffAllByColumnSideways();
  delay(time);
  turnEverythingOff();
  fountain();
  randomflicker();
  randomRain();
  goThroughAllLedsOneAtATime();
  propeller();
  flickerOff();
  turnEverythingOff();
  akshay();
  delay(2000);
  }

    //****************Functions******************
  
  void turnEverythingOff()
   {
     for(int i = 0; i<25; i++)
     {
     digitalWrite(column[i], 0);
     }
     for(int i = 0; i<5; i++)
     {
     digitalWrite(layer[i], 1);
     }
   }
  
  void turnEverythingOn()
  {
    for(int i = 0; i<25; i++)
    {
    digitalWrite(column[i], 1);
    }
    for(int i = 0; i<5; i++)
    {
    digitalWrite(layer[i], 0);
    }
  }
  void fountain()
  {
    int x=75;
    for(int j=0; j<2; j++)
    {
    digitalWrite(column[12], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 4; i>0; i--)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
    //digitalWrite(layer[0], 0);
    digitalWrite(column[6], 1);
    digitalWrite(column[8], 1);
    digitalWrite(column[16], 1);
    digitalWrite(column[18], 1);
    digitalWrite(column[12], 0);
    delay(x+100);
    digitalWrite(column[6], 0);
    digitalWrite(column[8], 0);
    digitalWrite(column[16], 0);
    digitalWrite(column[18], 0);
    delay(x);
    digitalWrite(column[0], 1);
    digitalWrite(column[4], 1);
    digitalWrite(column[20], 1);
    digitalWrite(column[24], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    }
  }
  
  void akshay()
  {
    int x=75;
    //turnEverythingOff();
    for(int i = 9; i<16; i++) //A
    {
    digitalWrite(column[i], 1);
    }
    digitalWrite(column[1], 1);
    digitalWrite(column[2], 1);
    digitalWrite(column[3], 1);
    digitalWrite(column[5], 1);
    digitalWrite(column[19], 1);
    digitalWrite(column[20], 1);
    digitalWrite(column[24], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 0; i<2; i++) //K
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+5], 1);
    digitalWrite(column[i+10], 1);
    digitalWrite(column[i+15], 1);
    digitalWrite(column[i+20], 1);
    }
    digitalWrite(column[4], 1);
    digitalWrite(column[8], 1);
    digitalWrite(column[12], 1);
    digitalWrite(column[18], 1);
    digitalWrite(column[24], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 0; i<5; i++)  //S
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+10], 1);
    digitalWrite(column[i+20], 1);
    }
    digitalWrite(column[5], 1);
    digitalWrite(column[19], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
   turnEverythingOff();
   for(int i = 9; i<16; i++) //H
    {
    digitalWrite(column[i], 1);
    }
    digitalWrite(column[0], 1);
    digitalWrite(column[4], 1);
    digitalWrite(column[5], 1);
    digitalWrite(column[19], 1);
    digitalWrite(column[20], 1);
    digitalWrite(column[24], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
   turnEverythingOff();
   for(int i = 9; i<16; i++) //A
    {
    digitalWrite(column[i], 1);
    }
    digitalWrite(column[1], 1);
    digitalWrite(column[2], 1);
    digitalWrite(column[3], 1);
    digitalWrite(column[5], 1);
    digitalWrite(column[19], 1);
    digitalWrite(column[20], 1);
    digitalWrite(column[24], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    digitalWrite(column[0], 1);  //Y
    digitalWrite(column[4], 1);
    digitalWrite(column[6], 1);
    digitalWrite(column[8], 1);
    digitalWrite(column[12], 1);
    digitalWrite(column[17], 1);
    digitalWrite(column[22], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 0; i<5; i++)  //S
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+10], 1);
    digitalWrite(column[i+20], 1);
    }
    digitalWrite(column[5], 1);
    digitalWrite(column[19], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 1; i<4; i++)  //O
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+20], 1);
    }
    digitalWrite(column[5], 1);
    digitalWrite(column[9], 1);
    digitalWrite(column[10], 1);
    digitalWrite(column[14], 1);
    digitalWrite(column[15], 1);
    digitalWrite(column[19], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 0; i<2; i++)  //N
    {
    digitalWrite(column[i+4], 1);
    digitalWrite(column[i+9], 1);
    digitalWrite(column[i+14], 1);
    digitalWrite(column[i+19], 1);
    }
    digitalWrite(column[0], 1);
    digitalWrite(column[24], 1);
    digitalWrite(column[6], 1);
    digitalWrite(column[12], 1);
    digitalWrite(column[18], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
    for(int i = 1; i<4; i++)  //I
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+20], 1);
    }
    digitalWrite(column[7], 1);
    digitalWrite(column[12], 1);
    digitalWrite(column[17], 1);
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
    }
    delay(1000);
    turnEverythingOff();
  }

  void newpattern()
  {
    for(int i = 0; i<5; i++)
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+4], 1);
    digitalWrite(column[i+8], 1);
    digitalWrite(column[i+12], 1);
    digitalWrite(layer[i], 0);
    delay(150);
    turnEverythingOff();
    }
    for(int j = 0; j<5; j++)
    {
    for(int i = 0; i<15; i++)
    {
    digitalWrite(column[i], 1);
    digitalWrite(layer[j], 0);
    delay(150);
    }
    turnEverythingOff();
    }
    for(int j = 4; j>=0; j--)
    {
    for(int i = 24; i>=0; i--)
    {
    digitalWrite(column[i], 1);
    digitalWrite(layer[j], 0);
    delay(150);
    }
    turnEverythingOff();
    }
    //turnEverythingOff();
    for(int i = 0; i<6; i++)
    {
    digitalWrite(column[i], 1);
    digitalWrite(column[i+5], 1);
    digitalWrite(column[i+10], 1);
    digitalWrite(column[i+15], 1);
    digitalWrite(layer[4-i], 0);
    delay(150);
    turnEverythingOff();
    }
  }

  void turnColumnsOff()
  {
    for(int i = 0; i<25; i++)
    {
    digitalWrite(column[i], 0);
    }
  }
  void flickerOn()
  {
    int i = 150;
    while(i != 0)
    {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
    }
  }
  
  void turnOnAndOffAllByLayerUpAndDownNotTimed()
  {
    int x = 75;
    for(int i = 3; i != 0; i--)
    {
    turnEverythingOn();
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
      for(int i = 0; i<5; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    }
  }
  
  
  void turnOnAndOffAllByColumnSideways()
  {
    int x = 75;
    turnEverythingOff();
    for(int i = 0; i<5; i++)
    {
    digitalWrite(layer[i], 0);
    }
    for(int y = 0; y<1; y++)
    {
    for(int i = 0; i<5; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 5; i<10; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 10; i<15; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 15; i<20; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 20; i<25; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 5; i<10; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 10; i<15; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 15; i<20; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 20; i<25; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 20; i<25; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 15; i<20; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 10; i<15; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 5; i<10; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 20; i<25; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 15; i<20; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 10; i<15; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 5; i<10; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    }
  }
  
  void layerstompUpAndDown()
  {
    int x = 75;
    for(int i = 0; i<5; i++)
    {
    digitalWrite(layer[i], 1);
    }
    for(int y = 0; y<2; y++)
    {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<5; i++)
      {
      digitalWrite(layer[i], 0);
      delay(x);
      digitalWrite(layer[i], 1);
      }
      for(int i = 5; i !=0; i--)
      {
      digitalWrite(layer[i-1], 0);
      delay(x);
      digitalWrite(layer[i-1], 1);
      }
    }
    for(int i = 0; i<5; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = 5; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
    }
  }
  
  void flickerOff()
  {
    turnEverythingOn();
    for(int i = 0; i!= 150; i+=5)
    {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
    }
  }
  
  
  void randomflicker()
  {
    turnEverythingOff();
    int x = 10;
    for(int i = 0; i !=750; i+=2)
    {
    int randomLayer = random(0,5);
    int randomColumn = random(0,24);
    
    digitalWrite(layer[randomLayer], 0);
    digitalWrite(column[randomColumn], 1);
    delay(x);
    digitalWrite(layer[randomLayer], 1);
    digitalWrite(column[randomColumn], 0);
    delay(x); 
    }
  }
  
  void randomRain()
  {
    turnEverythingOff();
    int x = 100;
    for(int i = 0; i!=60; i+=2)
    {
    int randomColumn = random(0,24);
    digitalWrite(column[randomColumn], 1);
    digitalWrite(layer[0], 0);
    delay(x+50);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 0);
    delay(x);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 0);
    delay(x);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 0);
    delay(x);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[4], 0);
    delay(x+50);
    digitalWrite(layer[4], 1);
    digitalWrite(column[randomColumn], 0);
    }
  }
  
  void propeller()
  {
    turnEverythingOff();
    int x = 75;
    for(int y = 5; y>0; y--)
    {
    for(int i = 0; i<6; i++)
    {
      digitalWrite(layer[y-1], 0);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[0], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[18], 1);
      digitalWrite(column[24], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[19], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[11], 1);
      digitalWrite(column[13], 1);
      digitalWrite(column[14], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[15], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[12], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[20], 1);
      digitalWrite(column[16], 1);
      digitalWrite(column[8], 1);
      digitalWrite(column[4], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[21], 1);
      digitalWrite(column[3], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[22], 1);
      digitalWrite(column[17], 1);
      digitalWrite(column[7], 1);
      digitalWrite(column[2], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[23], 1);
      digitalWrite(column[1], 1);
      delay(x);
    }
    }
   
    for(int y = 0; y<5; y++)
    {
    for(int i = 0; i<6; i++)
    {
      digitalWrite(layer[y], 1);
       turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[0], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[18], 1);
      digitalWrite(column[24], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[23], 1);
      digitalWrite(column[1], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[22], 1);
      digitalWrite(column[17], 1);
      digitalWrite(column[7], 1);
      digitalWrite(column[2], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[21], 1);
      digitalWrite(column[3], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[20], 1);
      digitalWrite(column[16], 1);
      digitalWrite(column[8], 1);
      digitalWrite(column[4], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[15], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[12], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[11], 1);
      digitalWrite(column[13], 1);
      digitalWrite(column[14], 1);
      delay(x);
      turnColumnsOff();
      digitalWrite(column[12], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[19], 1);
      delay(x);
    }
    }
    turnColumnsOff();
    delay(x);
  }
  
  void goThroughAllLedsOneAtATime()
  {
    int x = 15;
    turnEverythingOff();
    for(int y = 0; y<3; y++)
    {
    for(int count = 5; count != 0; count--)
    {
      digitalWrite(layer[count-1], 0);
      for(int i = 0; i<5; i++)
      {
      digitalWrite(column[i], 1);
      delay(x);
      digitalWrite(column[i], 0);
      delay(x);
      }
    digitalWrite(layer[count-1], 1);
    }
    for(int count = 0; count < 5; count++)
    {
      digitalWrite(layer[count], 0);
      for(int i = 5; i<10; i++)
      {
      digitalWrite(column[i], 1);
      delay(x);
      digitalWrite(column[i], 0);
      delay(x);
      }
    digitalWrite(layer[count], 1);
    }
    for(int count = 5; count != 0; count--)
    {
      digitalWrite(layer[count-1], 0);
      for(int i = 10; i<15; i++)
      {
      digitalWrite(column[i], 1);
      delay(x);
      digitalWrite(column[i], 0);
      delay(x);
      }
    digitalWrite(layer[count-1], 1);
    }
    for(int count = 0; count < 5; count++)
    {
      digitalWrite(layer[count], 0);
      for(int i = 15; i<20; i++)
      {
      digitalWrite(column[i], 1);
      delay(x);
      digitalWrite(column[i], 0);
      delay(x);
      }
    digitalWrite(layer[count], 1);
    }
    for(int count = 5; count != 0; count--)
    {
      digitalWrite(layer[count-1], 0);
      for(int i = 20; i<25; i++)
      {
      digitalWrite(column[i], 1);
      delay(x);
      digitalWrite(column[i], 0);
      delay(x);
      }
    digitalWrite(layer[count-1], 1);
    }
    }
  }
