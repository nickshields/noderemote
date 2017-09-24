#include <IRremote.h>
IRsend irsend;
/* 
*  Default is Arduino pin D11. 
*  You can change this to another available Arduino Pin.
*  Your IR receiver should be connected to the pin defined here
*/
int RECV_PIN = 11; 

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("NEC ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("SONY ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("RC5 ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("RC6 ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("PANASONIC ");
  }
  else if (results->decode_type == LG) {
    Serial.print("LG ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("JVC ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("AIWA_RC_T501 ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Whynter ");
  }
  Serial.print(results->value, DEC);
  Serial.print(" ");
  Serial.print(results->bits, DEC);
  delay(3000);
  Serial.flush();
}


void sendCode(unsigned long cmd, unsigned long rate, unsigned long protocol) {
  if (protocol == 0) {
    Serial.print("SENDING NEC ");
    for (int i = 0; i < 3; i++) {
    irsend.sendNEC(cmd, rate);  
    delay(40);
    }
  } 
  else if (protocol == 1) {
     for (int i = 0; i < 3; i++) {
    irsend.sendSony(cmd, rate);  
    delay(40);
    }
  } 
  else if (protocol == 2) {
    for (int i = 0; i < 3; i++) {
    irsend.sendPanasonic(cmd, rate);  
    delay(40);
    }
  }
  else if (protocol == 3) { //JVC
    for (int i = 0; i < 3; i++) {
    irsend.sendPanasonic(cmd, rate);  
    delay(40);
    }
  }
  else if (protocol == 4) {
    for (int i = 0; i < 3; i++) {
    irsend.sendRC5(cmd, rate);  
    delay(40);
    }
  }
  else if (protocol == 5) {
    for (int i = 0; i < 3; i++) {
    irsend.sendRC6(cmd, rate);  
    delay(40);
    }
  }
  else{
  }
}

unsigned long cmdProtocol=0;  // This is going to be the encoded information required to send the command.
unsigned long bitRate=0;
unsigned long integerValue=0;  // Max value is 65535 .. shouldnt it be larger
char incomingByte;

void loop() {
  if (irrecv.decode(&results)) {
    dump(&results);
    irrecv.resume(); // Receive the next value
  }

  //This is where the send logic goes :)
if (Serial.available() > 0) {
    cmdProtocol = 0;        
    integerValue=0;
    bitRate=0;
    //This while loop will read the settings needed to send the command.
    
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      cmdProtocol *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      cmdProtocol = ((incomingByte - 48) + cmdProtocol);
    }
    Serial.println(cmdProtocol);
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      bitRate *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      bitRate = ((incomingByte - 48) + bitRate);
    }


    Serial.println(bitRate);   // Do something with the value
    //now send the command
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    Serial.println(integerValue);   // Do something with the value
    Serial.println("Done one loop");
    sendCode(integerValue, bitRate, cmdProtocol);
}
}
