#define LeftFar A5
#define LeftNear A4
#define LeftCenter A3
#define RightCenter A2
#define RightNear A1
#define RightFar A0

#define LeftWall 9 
#define RightWall 7

#define CenterWall 8

#define LED 12

#define LeftMotor1 10 //DIGI   for pwm=10
#define LeftMotor2 6 //PWM
#define RightMotor1 5 //PWM
#define RightMotor2 11 //DIGI for pwm=11

int LeftFarReading;
int LeftNearReading;
int LeftCenterReading;
int RightFarReading;
int RightNearReading;
int RightCenterReading;

int cnt=0;
int flag=0;

void setup() {
  pinMode(LeftCenter, INPUT);
  pinMode(LeftNear, INPUT);
  pinMode(LeftFar, INPUT);
  pinMode(RightCenter, INPUT);
  pinMode(RightNear, INPUT);
  pinMode(RightFar, INPUT);

  pinMode(LED,OUTPUT);


  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);







Serial.begin(9600);
}

void loop() {

 
  if (analogRead(LeftCenter) > 200 && analogRead(RightCenter) > 200)    //straight path normal
  {
    digitalWrite(LED,LOW);
    
    analogWrite(LeftMotor1, 180);
    analogWrite(LeftMotor2, 0);
    analogWrite(RightMotor1, 180);
    analogWrite(RightMotor2, 0);
    
  }
/*if (analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter)>200 && analogRead(RightCenter)>200)     // plus junction or T junction to STOP
  {
    digitalWrite(LED,LOW);

    
   
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
        delay(50);

        if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        
        }

        else
        {
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
          
        }
  }*/



      
    if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter)>200 && analogRead(RightCenter)>200) // plus junction
    
    {
      digitalWrite(LED,LOW);

        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,0);

        delay(500);
    
   
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
        delay(50);

        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,0);

        delay(1000);
        
    
   if(analogRead(LeftCenter)>200 && analogRead(RightCenter)>200 )
   {

    
   if(cnt== 0 )
   {
   analogWrite(LeftMotor1, 200);
    analogWrite(LeftMotor2, 0);
    analogWrite(RightMotor1, 200);
    analogWrite(RightMotor2, 0);
    delay(100);
   cnt=1;
   }


    if(cnt== 1 )
    {
    analogWrite(LeftMotor1, 200);
    analogWrite(LeftMotor2, 0);
    analogWrite(RightMotor1, 200);
    analogWrite(RightMotor2, 0);
    delay(100);
   cnt=2;
    }
    

  /*  if(cnt== 2 )
    {
   
    analogWrite(LeftMotor1, 0);
    analogWrite(LeftMotor2, 0);
    analogWrite(RightMotor1, 180);
    analogWrite(RightMotor2, 0);
    delay(500);
    
 }*/


 

    }

   else  if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        
        }
     else if(analogRead(LeftFar)<200 && analogRead(RightFar)<200 && analogRead(LeftCenter<200) && analogRead(RightCenter)<200)
     {

      if(flag==0)
      {
        while(analogRead(LeftCenter)<200)
        {
         analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,180);
        }
        flag++;
        }
       
          
      }
      
      }
   

    if (analogRead(LeftCenter) < 200 && analogRead(RightCenter)>200)     //adjusting to right when left center on white 
     {
      digitalWrite(LED,LOW);
      
        if(analogRead(LeftCenter) < 200 && analogRead(RightCenter)<200)
        {
          analogWrite(LeftMotor1, 160);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
          }
      /*  analogWrite(LeftMotor1, 160);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,160);
        analogWrite(RightMotor2,0);

        delay(1);*/
        else{
        analogWrite(LeftMotor1, 160);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        }
       // delay(5);*/
        
    }

    if(analogRead(LeftCenter)>200 && analogRead(RightCenter)<200)    //adjusting to left when right center on white
    {
      digitalWrite(LED,LOW);
      if(analogRead(LeftCenter)<200 && analogRead(RightCenter)<200)
      {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 160);
        analogWrite(RightMotor2,0);
        }
       /* analogWrite(LeftMotor1, 160);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,160);
        analogWrite(RightMotor2,0);
        delay(1);*/
        else{
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 160);
        analogWrite(RightMotor2,0);
    }
      //  delay(5);
       
  }

     if(analogRead(LeftFar)>200 && analogRead(LeftCenter>200)  && analogRead(RightCenter)>200 ) //when leftfar and center sensors are on black then TAKE LEFT TURN
     {
      digitalWrite(LED,LOW);
        while( analogRead(RightNear)<200 || analogRead(RightFar)<200)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
        }
        delay(1);
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
     }
      /*  if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200)
        {
          analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);

        while(analogRead(RightCenter)<200 || analogRead(LeftCenter)<200)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 130);
        a/
        ']/nalogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
        }
        delay(1);
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        }*/
      

      if(analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200) //when rightfar and center sensors are on black then TAKE RIGHT TURN
     {
      digitalWrite(LED,LOW);
        while( analogRead(LeftNear)<200)
        {
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,0);
        }
        delay(1);
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
     }

        if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200) // when all the sensors are black then move forward and if the black
        {                                                                                                                    //region still exists then STOP
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
        delay(50);

        if(analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightCenter)>200)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        
        }

        
        }

      /* if( analogRead(LeftFar)>200 && analogRead(RightFar)>200 && analogRead(LeftCenter>200) && analogRead(RightFar)<200)
       {
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2, 0);
        analogWrite(RightMotor1,180);
        analogWrite(RightMotor2,0);

        delay(550);
        
        }*/
        
      



  /*  
   *   WALL CODE BEGINS HERE
   *  
   */
   
   if(digitalRead(LeftWall)==1 && digitalRead(RightWall)==1 && digitalRead(CenterWall)==0)  // if both walls are straight
     {  
        digitalWrite(LED, HIGH);

        analogWrite(LeftMotor1, 180);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
     }

    
            
      
      if(digitalRead(LeftWall)==0 && digitalRead(RightWall)==1 /*&& digitalRead(CenterWall)==0*/ ) // adjusting to left
      {
        digitalWrite(LED,HIGH);
       /*while(digitalRead(LeftWall)==0)
       {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,0);
        delay(1); */
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
       //}
       }

       if(digitalRead(LeftWall)==1 && digitalRead(RightWall)==0 /*&& digitalRead(CenterWall)==0 */) //adjusting to right
      {
        digitalWrite(LED,HIGH);
       /* while(digitalRead(RightWall)==0)
        {
          
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,0);
        delay(1); */
        analogWrite(LeftMotor1, 180);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
        
      // }
      }

      if(digitalRead(CenterWall)==1)// when any 90 degree turn is detected
      {
        digitalWrite(LED,HIGH);
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
      
        delay(500);
        
        if(digitalRead(LeftWall)==0 && digitalRead(RightWall)==1)// turn right 90 degrees
        {
          digitalWrite(LED, HIGH);
           while(digitalRead(CenterWall)==1)
         {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,100);
        analogWrite(RightMotor1, 100);
        analogWrite(RightMotor2,0);
       
         }
          
       }
       if(digitalRead(LeftWall)==1 && digitalRead(RightWall)==0)// turn left 90 degrees
       {
        digitalWrite(LED, HIGH);
        while(digitalRead(CenterWall)==1)
        {
        analogWrite(LeftMotor1,100);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,100);
       
        }
        }
        }

     /*   if(digitalRead(RightWall)==0 && digitalRead(LeftWall)==0 && digitalRead(CenterWall)==0) //when all wall sensors are not detected then go straight
        {
          digitalWrite(LED,HIGH);
         
        analogWrite(LeftMotor1,180);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 180);
        analogWrite(RightMotor2,0);
       
        
          }*/

      /*  if(digitalRead(LeftWall)==0 && digitalRead(RightWall)==1 && digitalRead(CenterWall)==1) // when path is turning left 90 degrees
      {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
      
        delay(500);

       
        while(digitalRead(CenterWall)==1)
        {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,100);
        analogWrite(RightMotor1, 100);
        analogWrite(RightMotor2,0);
       
        }

        
        
      }



      if(digitalRead(LeftWall)==1 && digitalRead(RightWall)==0 && digitalRead(Centerwall)==1) // when path is turning right 90 degrees
      {
        analogWrite(LeftMotor1,0);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1,0);
        analogWrite(RightMotor2,0);
      
        delay(500);

        while(digitalRead(CenterWall)==1)
        {
        analogWrite(LeftMotor1,100);
        analogWrite(LeftMotor2,0);
        analogWrite(RightMotor1, 0);
        analogWrite(RightMotor2,100);
       
        }
     }*/
}
  
