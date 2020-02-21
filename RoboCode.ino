String readString;
int x=0, y=90, z=120; 
#include <Servo.h> 
Servo sevoa, sevob, sevoc;

void setup() 
{
  Serial.begin(9600);


  sevoa.attach(9); 
  sevob.attach(10); 
  sevoc.attach(11);
  sevod.attach(12); 
  sevoa.write(x);
  sevob.write(y);
  sevoc.write(z);
  
}

void loop() 
{
  if (Serial.available() > 0){
    char m = Serial.read();
    if (m == '/'){
      if (readString.length() >1){
        Serial.println(readString);
        int temp = readString.toInt();
          Serial.print("writing Angle: ");
          Serial.println(temp);
          if(readString.indexOf('a') >=0){
            if (temp>x){
              for (int i=x; i<temp; i++){
                sevoa.write(i);
                delay(30);
              }
              x=temp;
            }
            else {
              for (int i=x; i>temp; i--){
                sevoa.write(i);
                delay(30);
              }
            }
            x=temp;
         }
//////////////////////////////////////////////////////////////////////////////         
          if(readString.indexOf('b') >=0){
            if (temp>y){
              for (int i=y; i<temp; i++){
                sevob.write(i);
                delay(30);
              }
              y=temp;
            }
            else {
              for (int i=y; i>temp; i--){
                sevob.write(i);
                delay(30);
              }
              y=temp;
            }
          }
///////////////////////////////////////////////////////////////////////
          if(readString.indexOf('c') >=0){
            if (temp>z){
              for (int i=z; i<temp; i++)
              {sevoc.write(i);
              delay(10);}
              z=temp;
            }
            else{
            for (int i=z; i>temp; i--){ 
              sevoc.write(i);
              delay(10);
              }
              z=temp;
            }
         }
       readString="";
      }
    }
    else{     
      readString += m;
    }
  }
}