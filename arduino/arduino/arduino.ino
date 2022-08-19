//Define IO Pins
#define ENA 6
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

//Define Drive Variables
#define DRIVETIME 250


// Setup Function
void setup() 
{
  // Serial Setup
  Serial.begin(9600);

  // Wait For Serial Connection
  while(!Serial)
  {
    ;
  }

  Serial.println("Serial Connection Ready");

  //Pin Setups
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// Main Loop
void loop() 
{
  // Serial Responses
  if (Serial.available() > 0)
  {
    char incoming = Serial.read();

    if(incoming == '~')
    {
      // Node Program Turn On
      Serial.println("Serial Connection Ready");
    } else
    {
      // Recieving Serial Data
      Serial.print("Recieved: ");
      Serial.println(incoming);

      // Set Drive Variables
      int drive_code = incoming - '0';
      int drive_length;

      // Check Drive Codes
      if(drive_code >= 0 && drive_code <= 7)
      {
        // Distinguish Short and Long Drive
        if(drive_code >=4)
        {
          drive_length = 1;
        } else
        {
          drive_length = 2;
        }

        // Drive
        switch (drive_code)
        {
          case 0:
            drive_fore(drive_length);
            break;
            
          case 1:
            drive_back(drive_length);
            break;
            
          case 2:
            drive_left(drive_length);
            break;
            
          case 3:
            drive_right(drive_length);
            break;
            
          case 4:
            drive_fore(drive_length);
            break;
            
          case 5:
            drive_back(drive_length);
            break;
            
          case 6:
            drive_left(drive_length);
            break;
            
          case 7:
            drive_right(drive_length);
            break;
        }
      } else
      {
        Serial.println("Unuseable Drive Code");
      }
    }
  }
}

//Drive Functions
void drive_left(int drive_length)
{
  // Turn On Wheels
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Left Wheels Backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right Wheels Foreward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Continue for 500ms * Drive Length ( 1 or 2 )
  delay(DRIVETIME * drive_length);

  // Shut Off Wheels
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
}

void drive_right(int drive_length)
{
  // Turn On Wheels
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Left Wheel Foreward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right Wheel Backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Continue for 500ms * Drive Length ( 1 or 2 )
  delay(DRIVETIME * drive_length);

  // Shut Off Wheels
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
}

void drive_fore(int drive_length)
{
  // Turn On Wheels
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Left Wheel Foreward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right Wheel Foreward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Continue for 500ms * Drive Length ( 1 or 2 )
  delay(DRIVETIME * drive_length);

  // Shut Off Wheels
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
}

void drive_back(int drive_length)
{
  //Turn On Wheels
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Left Wheel Backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right Wheel Backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Continue for 500ms * Drive Length ( 1 or 2 )
  delay(DRIVETIME * drive_length);

  // Shut Off Wheels
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
}
