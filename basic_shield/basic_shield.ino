 #include <IRremote.h>

int IR_Recv = 11;   //IR Receiver Pin 3
int bluePin = 2;
int greenPin = 3;
int yellowPin = 4;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(bluePin, OUTPUT);      // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(yellowPin, OUTPUT);      // sets the digital pin as output 

}
int i=1,j=1,k=1;
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 2160019894:  //when you press the 1 button
      {
        if(i%2==0)
        {
          digitalWrite(bluePin, LOW);
        }
        else
        {
          digitalWrite(bluePin, HIGH);
        }
        i=i+1;
        break;
      }   
       case 2160052534: 
       {
        if(j%2==0)
        {
          digitalWrite(greenPin, LOW);
        }
        else
        {
          digitalWrite(greenPin, HIGH);
        }
        j=j+1;
        break;
      }   
       case 2160014284: //when you press the 3 button
        {
        if(k%2==0)
        {
          digitalWrite(yellowPin, LOW);
        }
        else
        {
          digitalWrite(yellowPin, HIGH);
        }
        k=k+1;
        break;
      }   
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
