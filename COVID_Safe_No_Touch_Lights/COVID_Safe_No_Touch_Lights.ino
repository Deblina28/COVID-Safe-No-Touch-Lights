float prev = 0.0;
int c = -1, y = 0, ch = 0;
long ls = 0, tim = 0, tim2 = 0,b=0;
boolean f = true, state=true;

byte pat[]={0b00101010, 0b00010101};

void setup() {
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  Serial.begin (38400);
DDRB=0x3f;

  for(int i=0;i<1000;i++)
  b = b + analogRead(A0);

  b/=1000;


  for (;;)
  { 
    y = analogRead (A0);

    if (abs(y-b) > 4)
      {
        if(millis()-ls>30)
        {
        if (f)
        {
          tim = millis();
          f = false;
        }

        ls=millis();
        c++;
        }
      }


    if (millis() - tim > 2000)
    {
      if (c == 0)
        ch = 1;
      else if (c == 1)
        ch = 2;
      else if (c == 2)
        ch = 3;

      c = -1;

      tim = millis();
      f = true;
    }
    Serial.print (y);
    Serial.print (" ");
    Serial.print (ch);
    Serial.print (" ");
    Serial.println (c);
  
    if(ch==1)
    
    PORTB=0x3f;

    else if(ch==2)
    PORTB=0x00;

    else if(ch==3)
    {
      if(millis()-tim2>1000)
      {
      state=!state;
      tim2=millis();
      } 
     PORTB=pat[state];
    }
  }
  }

void loop() {
  Serial.println (analogRead (A0));
}
