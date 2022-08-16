void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial)
  {
    ;
  }

  Serial.println("Serial Connection Ready");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char incoming = Serial.read();

    if(incoming == '~')
    {
      Serial.println("Serial Connection Ready");
    } else
    {
      Serial.print("Recieved: ");
      Serial.println(incoming);
    }
    
  }
}

void drive_left()
{
  
}
