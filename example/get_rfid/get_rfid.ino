#include <RFID.h>
RFID rfid;
String id;
boolean success;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");

  // initial rfid return boolean, True = initial ok, false = initial fail
  if(rfid.init())
  {
    Serial.println("RFID Ready");
  }
  else
  {
    Serial.println("RFID Fail");
  }

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* return hex id
   *  getidHex(String &id, boolean &success)
   */  
  rfid.getIdHex(id, success);
  
  /* return decimal id
   *  getidDecimal(String &id, boolean &success)
   */ 
   
  //rfid.getIdDecimal(id, success);
  
  if(success)
  {
    Serial.println();
    Serial.print("Outside id = ");
    Serial.println(id);
  }
  else{
    Serial.println("Timed out waiting for a card");
  } 

  delay(1000);
}
