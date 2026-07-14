const int ldrPin = A0;  // Analog input pin for the photoresistor
const int ledPin = 9;   // Output pin for the LED


const int turnOnThreshold = 300;   
const int turnOffThreshold = 350;  

// Target brightness when ON (0-255). Set to 255 for max brightness.
const int activeBrightness = 255; 

bool isLightOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  analogWrite(ledPin, 0); 
  
  Serial.begin(9600); 
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue < turnOnThreshold && !isLightOn) {
      analogWrite(ledPin, activeBrightness);
      isLightOn = true;
      Serial.println("Threshold reached. Light ON.");
  }
  else if (ldrValue > turnOffThreshold && isLightOn) {
      analogWrite(ledPin, 0);
      isLightOn = false;
      Serial.println("Ambient light restored. Light OFF.");
  }

  // Small delay for stability
  delay(100); 
}
}
