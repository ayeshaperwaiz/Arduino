int blinkRate = 1000;  

void setup() {
  Serial.begin(9600);           // set up serial link
  pinMode(LED_BUILTIN, OUTPUT); // set up the pin with the built in LED as an output pin
  Serial.println(blinkRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  
char Receivebyte; 
  digitalWrite(LED_BUILTIN, HIGH);  // turn on LED
  delay(blinkRate);                 // wait one second
  digitalWrite(LED_BUILTIN, LOW);   // turn off LED
  delay(blinkRate);                 // wait one second

    Receivebyte = Serial.read(); 
    if (Receivebyte == '+' || '-') 
    {
      if (Receivebyte == '+') 
      {
          blinkRate  = blinkRate / 2; // divide the blink rate in half  
            if (blinkRate  <= 125)    // until 125 ms is reached 
            {
              blinkRate = 125;
              Serial.println("Max Speed : ");   // Print that max speed has been reached   
            }
            Serial.println(blinkRate);
      } 
      
      else if (Receivebyte == '-'){                              
        blinkRate  = blinkRate * 2;   // Multiply the blink rate by 2  
        if (blinkRate >= 4000)        // until 4000 ms is reached 
        {
          blinkRate = 4000; 
          Serial.println("Lowest Speed: "); // Print that lowest speed has been reached 
          }
          Serial.println(blinkRate);
        }
    
  }
  
}
