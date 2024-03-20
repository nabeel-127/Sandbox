/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
int a=0;
#define LS1 13      // left sensor_1
#define LS2 12     // left sensor_2
#define RS1 2      // right sensor_1
#define RS2 4      // right sensor_2
#define S_mid 7      // mid sensor

#define LM1 11    // left motor
#define LM2 10    // left motor
#define RM1 9    // right motor
#define RM2 6     // right motor

int turn = 0;
int direction = 0;

void setup()
{
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(S_mid, INPUT);
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

}

void loop()
{
  if (turn == 0 && direction == 1)
  {
    Right();
    delay(100);
    direction = 0;
    turn++;
  }
  if (turn == 1 && direction == -1)
  {
    Left();
    delay(100);
    direction = 0;
    turn++;
  }
  if (turn == 2 && direction == 1)
  {
    Right_Fast();
    delay(300);
    direction = 0;
    turn++;
  }
  if (turn == 3 && (direction == 1 || direction == -1))
  {
    delay(1000);
    direction = 0;
    turn++;
  }
  if (turn == 4 && direction == 1)
  {
    Right_Fast();
    delay(300);
    direction = 0;
    turn++;
  }
  if (turn == 5 && direction == 1)
  {
    Right_Fast();
    delay(200);
    direction = 0;
    turn++;
  }
  




























  
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {
    Forward();
  }
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == HIGH))
  {
    Forward();
  }
  
  //Right
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == LOW))
  {    
    Right();
    direction = 1;
  }
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == LOW) && (digitalRead(RS2)== HIGH))
  {    
    Right();
  }
  
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == HIGH))
  {  
    Right();  
    direction = 1;
  }
  //Right_Fast
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == LOW))
  {   
    Right(); 
    direction = 1;
  }
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == LOW))
  {   
    Right(); 
    direction = 1;
  }
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == LOW))
  {    
    Right();
    direction = 1;
  }
  
  //Left
  if((digitalRead(LS2) == LOW) && (digitalRead(LS1) == HIGH) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {    
    Left();
    direction = -1;
  }
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {    
    Left();
  }
  /*
  if((digitalRead(LS2) == HIGH) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {    
    Left();
  }
  */
  //Left_Fast
  if((digitalRead(LS2) == LOW) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == HIGH) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {    
    Left();
    direction = -1;
  }
  if((digitalRead(LS2) == LOW) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == HIGH) && (digitalRead(RS2) == HIGH))
  {    
    Left();
    direction = -1;
  }
  if((digitalRead(LS2) == LOW) && (digitalRead(LS1) == LOW) && (digitalRead(S_mid) == LOW) && (digitalRead(RS1) == LOW) && (digitalRead(RS2) == HIGH))
  {    
    Left();
    direction = -1;
  }

}

void Forward()
{
  analogWrite(LM1, 70);
  analogWrite(LM2, 0);
  analogWrite(RM1, 70);
  analogWrite(RM2, 0);
  delay(10);
}

void Right()
{
  analogWrite(LM1, 110);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 10);
  delay(10);
}

void Left()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 10);
  analogWrite(RM1, 110);  
  analogWrite(RM2, 0);
  delay(10);
}

void Right_Fast()
{
  analogWrite(LM1, 150);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 40);
  delay(10);
}

void Left_Fast()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 40);
  analogWrite(RM1, 150);
  analogWrite(RM2, 0);
  delay(10);
}
/*
void Reverse()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 70);
  analogWrite(RM1, 0);
  analogWrite(RM2, 70);
  delay(100);
}
*/

/*
void Stop()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
  //delay(0);
}
*/