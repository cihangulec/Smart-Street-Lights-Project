int ir1=2;
int ir2=3;
int ir3=4;
int ldr=A2;

int led1=9;
int led2=10;
int led3=11;

int proxy1=0;
int proxy2=0;
int proxy3=0;
int LDR_VALUE=0;

void setup() 
{
  //Serial.begin (9600);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ldr,INPUT);
}

void loop() 
{
  proxy1=digitalRead(ir1);
  proxy2=digitalRead(ir2);
  proxy3=digitalRead(ir3);
  LDR_VALUE=analogRead(ldr);

  //Serial.print("SENSOR 1");
  //Serial.println(proxy1);

  //Serial.print("SENSOR 2");
  //Serial.println(proxy2);

  //Serial.print("SENSOR 3");
  //Serial.println(proxy3);

  //Serial.print("LDR");
  //Serial.println(LDR_VALUE);

  if (LDR_VALUE < 150) //IF LIGHT IS NOT ENOUGH SYSTEM WILL WORK
  {
    //SENSOR 1, CONTROLS LED1
    
    if (proxy1==LOW)
    {
      analogWrite(led1,255);
    }
    
    //SENSOR 2, CONTROLS LED2

      if (proxy2==LOW)
    {
      analogWrite(led2,255);
      digitalWrite(led1,LOW);
    }

    //SENSOR 3, CONTROLS LED3

      if (proxy3==LOW)
    {
      analogWrite(led3,255);
      digitalWrite(led2,LOW);
    }
    else
    {
      digitalWrite(led3,LOW);
    }
  }
  else //IF LIGHT IS ENOUGH, SYSTEM WON'T WORK 
  {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  }
}
