/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);

  // Optional set pulse length.
  mySwitch.setPulseLength(189);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);

  Serial.println("<Arduino is ready>");
  
}

void loop() {
  long messageCodes[] = {5313843, 5313852, 5313987, 5313996, 5314307, 5314316, 5315843, 5315852, 5321987, 5321996};

  String message = "";
  int offset;
  if(Serial.available() > 0){
    message = Serial.readString();
    Serial.println("\"" + message + "\"");

    int numberOfSocket = atoi(message.substring(0, message.indexOf(" ")).c_str());
    String Command = message.substring(message.indexOf(" ")+1);
    
    
    if(Command == "ON"){
      offset = 0;
    }
    else if(Command == "OFF"){
      offset = 1;
    }
    else{
      Serial.println(Command + " is not a Command");
      return;
    }

    if(numberOfSocket < 5 && numberOfSocket >= 0){
      mySwitch.send(messageCodes[numberOfSocket*2 + offset], 24);
      Serial.println(String(messageCodes[numberOfSocket*2 + offset]) + " send");
    }
    else{
      Serial.println("Error Number conversion");
    }
    delay(1000);
  }

    
  
  /* Same switch as above, but using decimal code */
  
  
  
  delay(1000);  
}
