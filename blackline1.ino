#include "MotorClassL.h"
//tunr kasakasi er jonno c er value turn right er left e
//change l to 1 and m to 0 for white line
int l=0;//black
int m=1;//white
MotorClassL mc;
int replaystage=0;
int MBL = 60;//left
   int MBR =60 ;//right
int sensorPin[]={A0,A1,A2,A3,A4,A5,A6,A7};
int a[8];
int path[30];
int node=0;
int readLength;
void setup() {
  pinMode(13,OUTPUT);
    for(int i=0;i<8;i++){
    pinMode(sensorPin[i],INPUT);
    
  }// put your setup code here, to run on
  
Serial.begin(115200);
mc.motorForward(40,40);
delay(500);
//while(1){};
}
//+,T,|_,_|,L,R,B;white=1,black=0
void loop()//main code
{//delay(50);
MBL = 40;//left
   MBR =40 ;
  reading();
  int le;
  int re;
  if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)
  {mc.brake();
  delay(200);
  mc.motorForward(40,40);
  delay(500);//change time barai dibi left er jonno 100 kore
  mc.brake();
  reading();
  
  if((a[6]==0||a[7]==0)&&(a[1]==0||a[0]==0))
  {
  mc.brake();
  done();
  }

  else 
  {path[node]='L';
  node++;
    
   shortPath(); 
   turnleft();
  }
  }
   if(a[7]==0&&a[6]==0&&a[5]==0&&a[0]==1&&a[1]==1)
   {mc.brake();
  delay(200);
  mc.motorForward(40,40);
  delay(500);//change time barai dibi right er jonno 100 kore
  mc.brake();
  reading();
  if(a[0]==1&&a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==1&&a[6]==1&&a[7]==1)//R
  {mc.motorForward(-40,-40);
  delay(180);
  mc.brake();
  reading();
  
  if(a[0]==0&&a[1]==0&&a[2]==0)//Right er jonno
{mc.motorForward(40,40);
delay(500);// right er jonno eita barabi
path[node]='L';
node++;
shortPath();

turnleft();}
    else{path[node]='R';
  node++;
  shortPath();
  turnright();}
  }
   else{
  mc.motorForward(-40,-40);
  delay(180);//right er jono delay barai dibi 20ms
  mc.brake();
  reading();
  if(a[0]==0&&a[1]==0&&a[2]==0)
{mc.motorForward(40,40);
delay(500);
path[node]='L';
node++;
shortPath();

turnleft();}   
     else{mc.motorForward(40,40);
     delay(500);
     Serial.println("S");
   path[node]='S';
   node++;
   shortPath();
   int c=0;
   while(1)
   {
   delay(1);
   straight();
   if (c==100) break;
   c++;
   }
   
}
   }
   }
  if(a[0]==1&&a[1]==1&&a[3]==1&&a[4]==1&&a[5]==1&&a[6]==1&&a[7]==1&&a[2]==1)//B
  {mc.brake();
  delay(200);
  mc.motorForward(40,40);
  delay(400);
  mc.brake();
  reading();
 
  
    if(a[0]==1&&a[1]==1&&a[3]==1&&a[4]==1&&a[5]==1&&a[6]==1&&a[7]==1&&a[2]==1)
   { path[node]='B';
  node++;
  //shortPath();
  turnaround();}
  
  
  }
  
  straight();
}
  

 


void straight()
{Serial.println("Straight");
reading();
int le=lefterror();
int re=righterror();
int MR=MBR+0.7*(le-re);
int ML=MBL+0.7*(re-le);
 mc.motorForward(ML,MR);

}
void turnright()//turn right
{Serial.println("Turninh right started");
mc.brake();
//mc.motorForward(40,40);
//delay(10);
reading();

mc.motorForward(MBL,0);
delay(2400);//delay barai dibi jodi right turn turn finish na kore er beshi tunr nile komai dibi by 100/200
/*while(!(a[0]==1&&a[1]==1&&a[2]==1&&(a[3]==0&&a[4]==0)))
{reading();
  mc.motorForward(MBL,0);
  
}*/
mc.brake();
//mc.motorForward(40,40);
//delay(300);
int c=0;
if(replaystage==0){
while(1)
{c++;
MBR=-20;MBL=-20;
delay(1);
if (c==25) break;//jodi turn khub kasakasi hy er detect na kore taile eita komabi 50
straight();

}
c=0;
   while(1)
   {MBR=30;
MBL=30;
   delay(1);
   straight();
   if (c==100) break;
   c++;
   }}
   else{  while(1)
   {MBR=40;
MBL=40;
   delay(1);
   straight();
   if (c==100) break;
   c++;
   }
   }
   
   MBR=40;
MBL=40;
Serial.println("turning right end");

}
void turnleft()//left turn function
{
  Serial.println("turning left start");
mc.brake();

mc.motorForward(-40,-40);
delay(130);
mc.motorForward(0,MBR);
delay(2400);//delay barai dibi jodi left turn finish na kore er beshi tunr nile komai dibi

/*while(!(a[0]=1&&a[1]==1&&a[2]==1&&a[3]==0&&a[4]==0&&a[6]==1))
{reading();
  mc.motorForward(0,MBR);
  
}*/
mc.brake();
//mc.motorForward(40,40);
//delay(500);
//straight();
//delay(1000);
//while(1){}
int c=0;
if(replaystage==0)
{while(1)
{MBR=-20;
MBL=-20;
  c++;
delay(1);
if (c==25) break;//jodi turn khub kasakasi hy er detect na kore taile eita komabi 50
straight();

}
c=0;
   while(1)
   {MBR=30;
MBL=30;
   delay(1);
   straight();
   if (c==100) break;
   c++;
   }}
   else{  while(1)
   {MBR=40;
MBL=40;
   delay(1);
   straight();
   if (c==100) break;
   c++;
   }
   }
MBL=40;
MBR=40;
  Serial.println("turning left finished");
}
void turnaround()//U turn
{Serial.println("turning  around start");
mc.motorForward(MBL,MBR);
delay(900);//block theke ektu jodi agano dorkar hy(jodi turn gula kasakasi thake ei delay barai dibi 100
  mc.motorForward(-MBL,MBR+100);
delay(200);
mc.brake();

mc.motorForward(-MBL,-MBR);
delay(200);//if pishaite hobe beshi mne hy tokhn delay 100 kore barabi er viseversa
mc.motorForward(-20,0);
delay(100);
mc.motorForward(0,MBR);
delay(2500);
/*while(!(a[7]=1&&a[6]==1&&a[5]==0&&a[3]==0&&a[4]==0))
{reading();
  mc.motorForward(0,MBR);
  
} */int c=0;

while(1)
{c++;

delay(1);
if (c==120) break;//jodi turn khub kasakasi hy er detect na kore taile eita komabi 50
straight();

}
mc.brake();
Serial.println("turning  around end");
  
}

void reading()
{  for(int i=0;i<8;i++)
{  if(analogRead(sensorPin[i])>550){
a[i]=l;//black
}
else{a[i]=m;}//white
Serial.print("\t");
Serial.print(a[i]);
} 
 Serial.println("\n"); // put your main code here, to run repeatedly:



}
void shortPath()
{
  int shortDone=0;
  if(path[node-3]=='L' && path[node-1]=='R'&& shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='B';
    Serial.println("test1");
    shortDone=1;
    node++;
  } 
  if(path[node-3]=='L' && path[node-1]=='S' && shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='R';
    Serial.println("test2");
    shortDone=1;
    node++;
  } 
  if(path[node-3]=='R' && path[node-1]=='L' && shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='B';
    Serial.println("test3");
    shortDone=1;
    node++;
  } 
  if(path[node-3]=='S' && path[node-1]=='L' && shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='R';
    Serial.println("test4");
    shortDone=1;
    node++;
  }   
  if(path[node-3]=='S' && path[node-1]=='S' && shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='B';
    Serial.println("test5");
    shortDone=1;
    node++;
  }
  if(path[node-3]=='L' && path[node-1]=='L' && shortDone==0&&path[node-2]=='B')
  {
    node-=3;
    path[node]='S';
    Serial.println("test6");
    shortDone=1;
    node++;
  }
 // path[node+1]='D';
 // path[node+2]='D';
  //node++;
  //Serial.print("Path length: ");
  //Serial.println(node);
 //printPath();  
}
void printPath()
{
  Serial.println("+++++++++++++++++");
  int x;
  int j=0;
  int b[30];
  
  for(x=node-1;x>=0;x--)
  {if(path[x]=='D') continue;
  b[j]=path[x];
  if(path[x]=='R')
  {b[j]='L';
  
  
  }
  if(path[x]=='L')
  {
  b[j]='R';
  }
  
  j++;
  
  }
  b[j]='D';
  for(x=0;x<node;x++)
  {path[x]=b[x];
  }
  
  for(x=0;x<node;x++)
  {
    Serial.println(path[x]);
   
  }
  Serial.println("+++++++++++++++++");
}
void done()
{
 mc.brake();
  replaystage=1;
  path[node]='D';
  node++;
  printPath();  
  int c=0;
  while(1)
  {reading();
 if(a[6]==1&&a[1]==1) break;
    digitalWrite(13, LOW);
    delay(150);
    digitalWrite(13, HIGH);
    delay(150);
    c++;
    if(c==5) break;
    
  }
 // while(1){}
  delay(500);
  readLength=0;
  turnaround();
  replay();
}
void replay()
{//delay(100);
MBR=40;
MBL=40;
  reading();

    straight();
  
  if((a[0]==0&&a[1]==0)||(a[6]==0&&a[7]==0)&&a[3]==0&&a[4]==0)
  {
    if(path[readLength]=='D')
    {
      straight();
      delay(100);
     mc.brake();
      endMotion();
    }
    if(path[readLength]=='L')
    {
      straight();
      //delay(300);
      turnleft();
    }
    if(path[readLength]=='R')
    {
      straight();
      //delay(300);
      turnright();
    }
    if(path[readLength]=='S')
    {
      straight();
      int c=0;
      while(1)
      {straight();
      c++;
      delay(1);
      if(c==300) break;}
     // delay(300);
      straight();
    }
    readLength++;
  }
  replay();
}
void endMotion(){
  Serial.println("endmotion");
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
      digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
        digitalWrite(13, LOW);
    delay(500);
  while(1) {}
}
int lefterror()
{
  reading();
  int ler=20*!(a[0])+20*!(a[1])+10*!(a[2]);
return ler;}
int righterror()
{reading();
  int rer=20*!(a[7])+20*!(a[6])+10*!(a[5]);
return rer;}
