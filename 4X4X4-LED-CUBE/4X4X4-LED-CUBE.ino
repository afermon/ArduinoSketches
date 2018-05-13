/*
  4x4x4 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-0
  (1,2)-1
  (1,3)-2
  (1,4)-3
  (2,1)-4
  (2,2)-5
  (2,3)-6
  (2,4)-7
  (3,1)-8
  (3-2)-9
  (3-3)-10
  (3,4)-11
  (4,1)-A5
  (4,2)-A4
  (4,3)-A3
  (4,4)-A2
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-13
  d-12
*/
//initializing and declaring led rows
  int column[16]={0,1,2,3,4,5,6,7,8,9,10,11,A5,A4,A3,A2};
//initializing and declaring led layers
  int layer[4]={A0,A1,13,12}; 
//Time between animations
  int time = 1; //250
 
void setup()
{
  //setting rows to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
  randomSeed(analogRead(10));
}


void loop()
{
  turnEverythingOff();//turn all off
  flickerOn();
  turnEverythingOn();//turn all on
  delay(time);
  turnOnAndOffAllByLayerUpAndDownNotTimed();
  layerstompUpAndDown();
  turnOnAndOffAllByColumnSideways();
  delay(time);
  aroundEdgeDown();
  turnEverythingOff();
  randomflicker();
  randomRain();
  diagonalRectangle();
  goThroughAllLedsOneAtATime();
  propeller();
  spiralInAndOut();
  flickerOff();
  turnEverythingOff();
  delay(2000);
}


//Animations

void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 0); //OFF
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 0); //OFF
   }
 }
 

void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1); //ON
  }
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1); //ON
  }
}

void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0); //OFF
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
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0); //OFF
      delay(x);
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1); //ON
      delay(x);
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 0); //OFF
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1); //ON
      delay(x);
    }
  }
}

void turnOnAndOffAllByColumnSideways()
{
  int x = 75;
  turnEverythingOff();
  //turn on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1); //ON
  }
  for(int y = 0; y<3; y++)
  {
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn on 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1); //ON
      delay(x);
    }
    //turn off 12-15
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 8-11
    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0); //OFF
      delay(x);
    }
  }
}

void layerstompUpAndDown()
{
  int x = 75;
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0); //OFF
  }
  for(int y = 0; y<5; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<4; i++)
      {
        digitalWrite(layer[i], 1); //ON
        delay(x);
        digitalWrite(layer[i], 0); //OFF
      }
      for(int i = 4; i !=0; i--)
      {
        digitalWrite(layer[i-1], 1); //ON
        delay(x);
        digitalWrite(layer[i-1], 0); //OFF
      }
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1); //ON
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0); //OFF
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

void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = 4; i != 0; i--)
    {
      digitalWrite(layer[i-1], 1); //ON
      digitalWrite(column[5], 1); //ON
      digitalWrite(column[6], 1); //ON
      digitalWrite(column[9], 1); //ON
      digitalWrite(column[10], 1); //ON
      
      digitalWrite(column[0], 1); //ON
      delay(x);
      digitalWrite(column[0], 0); //OFF
      digitalWrite(column[4], 1); //ON
      delay(x);
      digitalWrite(column[4], 0); //OFF
      digitalWrite(column[8], 1); //ON
      delay(x);
      digitalWrite(column[8], 0); //OFF
      digitalWrite(column[12], 1); //ON
      delay(x);
      digitalWrite(column[12], 0); //OFF
      digitalWrite(column[13], 1); //ON
      delay(x);
      digitalWrite(column[13], 0); //OFF
      digitalWrite(column[14], 1); //ON
      delay(x);
      digitalWrite(column[14], 0); //OFF
      digitalWrite(column[15], 1); //ON
      delay(x);
      digitalWrite(column[15], 0); //OFF
      digitalWrite(column[11], 1); //ON
      delay(x);
      digitalWrite(column[11], 0); //OFF
      digitalWrite(column[7], 1); //ON
      delay(x);
      digitalWrite(column[7], 0); //OFF
      digitalWrite(column[3], 1); //ON
      delay(x);
      digitalWrite(column[3], 0); //OFF
      digitalWrite(column[2], 1); //ON
      delay(x);
      digitalWrite(column[2], 0); //OFF
      digitalWrite(column[1], 1); //ON
      delay(x);
      digitalWrite(column[1], 0); //OFF
    }
  }
}

void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  
  digitalWrite(layer[randomLayer], 1); //ON
  digitalWrite(column[randomColumn], 1); //ON
  delay(x);
  digitalWrite(layer[randomLayer], 0); //OFF
  digitalWrite(column[randomColumn], 0); //OFF
  delay(x); 
  }
}

void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    digitalWrite(column[randomColumn], 1); //ON
    digitalWrite(layer[0], 1); //ON
    delay(x+50);
    digitalWrite(layer[0], 0); //OFF
    digitalWrite(layer[1], 1); //ON
    delay(x);
    digitalWrite(layer[1], 0); //OFF
    digitalWrite(layer[2], 1); //ON
    delay(x);
    digitalWrite(layer[2], 0); //OFF
    digitalWrite(layer[3], 1); //ON
    delay(x+50);
    digitalWrite(layer[3], 0); //OFF
    digitalWrite(column[randomColumn], 0); //OFF
  }
}

void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[3], 1); //ON
    digitalWrite(layer[2], 1); //ON
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[1], 1); //ON
    digitalWrite(layer[2], 1); //ON
    delay(x);
    turnEverythingOff();
    //bottom right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[0], 1); //ON
    digitalWrite(layer[1], 1); //ON
    delay(x);
    turnEverythingOff();
    //bottom middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[0], 1); //ON
    digitalWrite(layer[1], 1); //ON
    delay(x);
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[0], 1); //ON
    digitalWrite(layer[1], 1); //ON
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[1], 1); //ON
    digitalWrite(layer[2], 1); //ON
    delay(x);
    turnEverythingOff();
    //top right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[2], 1); //ON
    digitalWrite(layer[3], 1); //ON
    delay(x);
    turnEverythingOff();
    //top middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 1); //ON
    }
    digitalWrite(layer[2], 1); //ON
    digitalWrite(layer[3], 1); //ON
    delay(x);
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 1); //ON
  }
  digitalWrite(layer[3], 1); //ON
  digitalWrite(layer[2], 1); //ON
  delay(x);
  turnEverythingOff();
}

void propeller()
{
  turnEverythingOff();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1); //ON
      //a1
      turnColumnsOff();
      digitalWrite(column[0], 1); //ON
      digitalWrite(column[5], 1); //ON
      digitalWrite(column[10], 1); //ON
      digitalWrite(column[15], 1); //ON
      delay(x);
      //b1
      turnColumnsOff();
      digitalWrite(column[4], 1); //ON
      digitalWrite(column[5], 1); //ON
      digitalWrite(column[10], 1); //ON
      digitalWrite(column[11], 1); //ON
      delay(x);
      //c1
      turnColumnsOff();
      digitalWrite(column[6], 1); //ON
      digitalWrite(column[7], 1); //ON
      digitalWrite(column[8], 1); //ON
      digitalWrite(column[9], 1); //ON
      delay(x);
      //d1
      turnColumnsOff();
      digitalWrite(column[3], 1); //ON
      digitalWrite(column[6], 1); //ON
      digitalWrite(column[9], 1); //ON
      digitalWrite(column[12], 1); //ON
      delay(x);
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 1); //ON
      digitalWrite(column[6], 1); //ON
      digitalWrite(column[9], 1); //ON
      digitalWrite(column[13], 1); //ON
      delay(x);
      //d3
      turnColumnsOff();
      digitalWrite(column[1], 1); //ON
      digitalWrite(column[5], 1); //ON
      digitalWrite(column[10], 1); //ON
      digitalWrite(column[14], 1); //ON
      delay(x);
    }
  }
  //d4
  turnColumnsOff();
  digitalWrite(column[0], 1); //ON
  digitalWrite(column[5], 1); //ON
  digitalWrite(column[10], 1); //ON
  digitalWrite(column[15], 1); //ON
  delay(x);
}

void spiralInAndOut()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 0); //OFF
    delay(x);
    digitalWrite(column[1], 0); //OFF
    delay(x);
    digitalWrite(column[2], 0); //OFF
    delay(x);
    digitalWrite(column[3], 0); //OFF
    delay(x);
    digitalWrite(column[7], 0); //OFF
    delay(x);
    digitalWrite(column[11], 0); //OFF
    delay(x);
    digitalWrite(column[15], 0); //OFF
    delay(x);
    digitalWrite(column[14], 0); //OFF
    delay(x);
    digitalWrite(column[13], 0); //OFF
    delay(x);
    digitalWrite(column[12], 0); //OFF
    delay(x);
    digitalWrite(column[8], 0); //OFF
    delay(x);
    digitalWrite(column[4], 0); //OFF
    delay(x);
    digitalWrite(column[5], 0); //OFF
    delay(x);
    digitalWrite(column[6], 0); //OFF
    delay(x);
    digitalWrite(column[10], 0); //OFF
    delay(x);
    digitalWrite(column[9], 0); //OFF
    delay(x);
    //spiral out counter clockwise
    digitalWrite(column[9], 1); //ON
    delay(x);
    digitalWrite(column[10], 1); //ON
    delay(x);
    digitalWrite(column[6], 1); //ON
    delay(x);
    digitalWrite(column[5], 1); //ON
    delay(x);
    digitalWrite(column[4], 1); //ON
    delay(x);
    digitalWrite(column[8], 1); //ON
    delay(x);
    digitalWrite(column[12], 1); //ON
    delay(x);
    digitalWrite(column[13], 1); //ON
    delay(x);
    digitalWrite(column[14], 1); //ON
    delay(x);
    digitalWrite(column[15], 1); //ON
    delay(x);
    digitalWrite(column[11], 1); //ON
    delay(x);
    digitalWrite(column[7], 1); //ON
    delay(x);
    digitalWrite(column[3], 1); //ON
    delay(x);
    digitalWrite(column[2], 1); //ON
    delay(x);
    digitalWrite(column[1], 1); //ON
    delay(x);
    digitalWrite(column[0], 1); //ON
    delay(x);
    //spiral in counter clockwise
    digitalWrite(column[0], 0); //OFF
    delay(x);
    digitalWrite(column[4], 0); //OFF
    delay(x);
    digitalWrite(column[8], 0); //OFF
    delay(x);
    digitalWrite(column[12], 0); //OFF
    delay(x);
    digitalWrite(column[13], 0); //OFF
    delay(x);
    digitalWrite(column[14], 0); //OFF
    delay(x);
    digitalWrite(column[15], 0); //OFF
    delay(x);
    digitalWrite(column[11], 0); //OFF
    delay(x);
    digitalWrite(column[7], 0); //OFF
    delay(x);
    digitalWrite(column[3], 0); //OFF
    delay(x);
    digitalWrite(column[2], 0); //OFF
    delay(x);
    digitalWrite(column[1], 0); //OFF
    delay(x);
    digitalWrite(column[5], 0); //OFF
    delay(x);
    digitalWrite(column[9], 0); //OFF
    delay(x);
    digitalWrite(column[10], 0); //OFF
    delay(x);
    digitalWrite(column[6], 0); //OFF
    delay(x);
    // spiral out clockwise
    digitalWrite(column[6], 1); //ON
    delay(x);
    digitalWrite(column[10], 1); //ON
    delay(x);
    digitalWrite(column[9], 1); //ON
    delay(x);
    digitalWrite(column[5], 1); //ON
    delay(x);
    digitalWrite(column[1], 1); //ON
    delay(x);
    digitalWrite(column[2], 1); //ON
    delay(x);
    digitalWrite(column[3], 1); //ON
    delay(x);
    digitalWrite(column[7], 1); //ON
    delay(x);
    digitalWrite(column[11], 1); //ON
    delay(x);
    digitalWrite(column[15], 1); //ON
    delay(x);
    digitalWrite(column[14], 1); //ON
    delay(x);
    digitalWrite(column[13], 1); //ON
    delay(x);
    digitalWrite(column[12], 1); //ON
    delay(x);
    digitalWrite(column[8], 1); //ON
    delay(x);
    digitalWrite(column[4], 1); //ON
    delay(x);
    digitalWrite(column[0], 1); //ON
    delay(x);
  }
}

void goThroughAllLedsOneAtATime()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1); //ON
      for(int i = 0; i<4; i++)
      {
        digitalWrite(column[i], 1); //ON
        delay(x);
        digitalWrite(column[i], 0); //OFF
        delay(x);
      }
    digitalWrite(layer[count-1], 0); //OFF
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1); //ON
      for(int i = 4; i<8; i++)
      {
        digitalWrite(column[i], 1); //ON
        delay(x);
        digitalWrite(column[i], 0); //OFF
        delay(x);
      }
    digitalWrite(layer[count], 0); //OFF
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1); //ON
      for(int i = 8; i<12; i++)
      {
        digitalWrite(column[i], 1); //ON
        delay(x);
        digitalWrite(column[i], 0); //OFF
        delay(x);
      }
    digitalWrite(layer[count-1], 0); //OFF
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1); //ON
      for(int i = 12; i<16; i++)
      {
        digitalWrite(column[i], 1); //ON
        delay(x);
        digitalWrite(column[i], 0); //OFF
        delay(x);
      }
    digitalWrite(layer[count], 0); //OFF
    }
  }
}
