const  int trigger=3;
	const  int echo=2;
	float  distance;
	float dist_inches;

  //sensor2
  const  int btrigger=5;
	const  int becho=4;
	float  bdistance;
	float bdist_inches;
	
	void setup(){
		Serial.begin(9600);
		pinMode(trigger,OUTPUT);
		pinMode(echo,INPUT);
    pinMode(btrigger,OUTPUT);
		pinMode(becho,INPUT);
    pinMode(6,OUTPUT);
		pinMode(7,OUTPUT);
    }
	
	void loop(){
		// Trigger the sensor to start measurement
		// Set up trigger
		digitalWrite(trigger,LOW);
		delayMicroseconds(5);
		
		//Start Measurement
		digitalWrite(trigger,HIGH);
		delayMicroseconds(10);
		digitalWrite(trigger,LOW);
		
		// Acquire and convert to inches
		distance=pulseIn(echo,HIGH);
		distance=distance*0.0001657;
		dist_inches=distance*39.37;
 
		// print the value on the serial monitor
		Serial.print(dist_inches);
		Serial.println(" inches");
		delay(200);
      if (dist_inches<=8)
      {
        digitalWrite(7,HIGH);
        // digitalWrite(6,HIGH);
      }
      else
      {
        digitalWrite(7,LOW);
        // digitalWrite(6,LOW);
      }
      
      // sensor2

      // Trigger the sensor to start measurement
		// Set up trigger
		digitalWrite(btrigger,LOW);
		delayMicroseconds(5);
		
		//Start Measurement
		digitalWrite(btrigger,HIGH);
		delayMicroseconds(10);
		digitalWrite(btrigger,LOW);
		
		// Acquire and convert to inches
		bdistance=pulseIn(becho,HIGH);
		bdistance=bdistance*0.0001657;
		bdist_inches=bdistance*39.37;
 
		// print the value on the serial monitor
		Serial.print(bdist_inches);
		Serial.println(" inches_b");
		delay(200);
      if (bdist_inches<=8)
      {
        digitalWrite(6,HIGH);
        // digitalWrite(6,HIGH);
      }
      else
      {
        digitalWrite(6,LOW);
        // digitalWrite(6,LOW);
      }
      
	}