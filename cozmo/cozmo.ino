#include<Servo.h>
const int l1=3;
const int l2=5;
const int m1=6;
const int m2=9;
Servo myservo[4];
void setup() {
  Serial.begin(115200);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  myservo[0].attach(4); //left hand
  myservo[1].attach(7); //right hand
  myservo[2].attach(8); //neck
  myservo[3].attach(10); //head
  rst();
}

void loop() {
  if(Serial.available())
  {
    char x=Serial.read();
    if(x=='1')
    {
      lft_shake();
    }
    else if(x=='2')
    {
      right_shake();
    }
    else if(x=='3')
    {
      shake_head();
    }
    else if(x=='4')
    {
      nod();
    }
    else if(x=='5')
    {
      forward();
    }
    else if(x=='6')
    {
      left();
    }
    else if(x=='7')
    {
      right();
    }
    else if(x=='8')
    {
      back();
    }
    else if(x=='9')
    {
      sto();
    }
    else if(x=='10')
    {
      char y=Serial.read();
      if(y=='u')
      tracking(3, 1);
      else if(y=='d')
      tracking(3, -1);
      else if(y=='l')
      tracking(2, -1);
      else if(y=='l')
      tracking(2, 1);
    }
    else
    {
      rst();
    }
  }

}
int ang[4];
void rst()
{
  ang[0] = myservo[0].read();
  ang[1] = myservo[1].read();
  ang[2] = myservo[2].read();
  ang[3] = myservo[3].read();
  if(ang[0]!=0)
  {
    for(int i=ang[0];i>=0;i--)
    {
      myservo[1].write(i);
      delay(10);
    }
  }
    if(ang[1]!=0)
  {
    for(int i=ang[0];i>=0;i--)
    {
      myservo[1].write(i);
      delay(10);
    }
  }
  if(ang[2]<90)
  {
    for(int i=ang[2];i<=90;i++)
    {
      myservo[2].write(i);
      delay(10);
    }
  }
  if(ang[2]>90)
  {
    for(int i=ang[2];i>=90;i--)
    {
      myservo[2].write(i);
      delay(10);
    }
  }
    if(ang[3]<90)
  {
    for(int i=ang[3];i<=90;i++)
    {
      myservo[3].write(i);
      delay(10);
    }
  }
  if(ang[3]>90)
  {
    for(int i=ang[3];i>=90;i--)
    {
      myservo[3].write(i);
      delay(10);
    }
  }
}
void lft_shake()
{
  for(int i=0;i<=60;i++)
  {
    myservo[0].write(i);
    delay(10);
  }
  delay(500);
  for(int i=1;i<=5;i++)
  {
    for(int j=60;j>=120;j++)
    {
      myservo[0].write(i);
      delay(10);
    }
    for(int j=120;j>=60;j--)
    {
      myservo[0].write(i);
      delay(10);
    }
  }
}
void right_shake()
{
  for(int i=0;i<=60;i++)
  {
    myservo[1].write(i);
    delay(10);
  }
  delay(500);
  for(int i=1;i<=5;i++)
  {
    for(int j=60;j>=120;j++)
    {
      myservo[1].write(i);
      delay(10);
    }
    for(int j=120;j>=60;j--)
    {
      myservo[1].write(i);
      delay(10);
    }
  }
}
void shake_head()
{
  for(int i=1;i<=3;i++)
  {
    for(int j=90;j>=45;j--)
    {
      myservo[2].write(i);
      delay(10);
    }
    for(int j=45;j<=135;j++)
    {
      myservo[2].write(i);
      delay(10);
    }
    for(int j=135;j>=90;j--)
    {
      myservo[2].write(i);
      delay(10);
    }
  }
}
void nod()
{
  for(int i=1;i<=3;i++)
  {
    for(int j=90;j>=45;j--)
    {
      myservo[3].write(i);
      delay(10);
    }
    for(int j=45;j<=135;j++)
    {
      myservo[3].write(i);
      delay(10);
    }
    for(int j=135;j>=90;j--)
    {
      myservo[3].write(i);
      delay(10);
    }
  }  
}
void forward()
{
  analogWrite(l1,150);
  analogWrite(l2,0);
  analogWrite(m1,150);
  analogWrite(m2,0);
}
void back()
{
  analogWrite(l2,150);
  analogWrite(l1,0);
  analogWrite(m2,150);
  analogWrite(m1,0);
}
void left()
{  
  analogWrite(l2,150);
  analogWrite(l1,0);
  analogWrite(m1,150);
  analogWrite(m2,0);
}
void right()
{  
  analogWrite(l1,150);
  analogWrite(l2,0);
  analogWrite(m2,150);
  analogWrite(m1,0);
}
void sto()
{
  
  analogWrite(l1,0);
  analogWrite(l2,0);
  analogWrite(m1,0);
  analogWrite(m2,0);
}
void tracking(int servo_number, int an) // track horizontal face movement
{
  ang[servo_number]=myservo[servo_number].read();
  myservo[servo_number].write(ang+an);
}
