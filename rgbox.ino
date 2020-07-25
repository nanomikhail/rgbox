#define CLK 7
#define DT 4
#define SW 8
#include "GyverEncoder.h"
Encoder enc1(CLK, DT, SW);

int rVal = 127;int gVal = 1;int bVal = 127;int rDir = -1;int gDir = 1;int bDir = -1;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
    int r=0;int g=0;int b=0;int rbuff=0;int gbuff=0;int bbuff=0;int color=1;int mode=0;int del=3000;bool rainbow=false;bool buff=true;
    while(1){
        enc1.tick();
        
        switch (mode) {
          case 0:
              if(buff==true){r=rbuff;g=gbuff;b=bbuff;buff=false;}
              if(color==1){
                if (enc1.isRight()){ r--;if(r<=1){r=0;}  }
                if (enc1.isLeft()) { r++;if(r>=254){r=254;}  } 
                if (enc1.isRightH()){ r=r-10;if(r<=1){r=0;}  }
                if (enc1.isLeftH()) { r=r+10;if(r>=254){r=254;}  } 
                analogWrite(3,3);analogWrite(5,0);analogWrite(6,0);
                rbuff=r;
              }
              if(color==2){
                if (enc1.isRight()){ g--;if(g<=1){g=0;}  }
                if (enc1.isLeft()) { g++;if(g>=254){g=254;}  } 
                if (enc1.isRightH()){ g=g-10;if(g<=1){g=0;}  }
                if (enc1.isLeftH()) { g=g+10;if(g>=254){g=254;}  } 
                analogWrite(3,0);analogWrite(5,2);analogWrite(6,0);
                gbuff=g;
              }
              if(color==3){
                if (enc1.isRight()){ b--;if(b<=1){b=0;}  }
                if (enc1.isLeft()) { b++;if(b>=254){b=254;}  } 
                if (enc1.isRightH()){ b=b-10;if(b<=1){b=0;}  }
                if (enc1.isLeftH()) { b=b+10;if(b>=254){b=254;}  } 
                analogWrite(3,0);analogWrite(5,0);analogWrite(6,3);
                bbuff=b;
              }
              if (enc1.isClick()){ color++;}
              if(color==4) color=1;
          break;
          case 1:
              if(buff==true){r=rbuff;g=gbuff;b=bbuff;buff=false;}
              if (enc1.isRight()){ r--;g--;b--;if(r<=1){r=0;}if(g<=1){g=0;}if(b<=1){b=0;}  }
              if (enc1.isLeft()) { if(r!=0)r++;if(g!=0)g++;if(b!=0)b++;if(r>=254){r=254;}if(g>=254){g=254;}if(b>=254){b=254;}  } 
              analogWrite(3,3);analogWrite(5,3);analogWrite(6,3);
              rbuff=r;gbuff=g;bbuff=b;
          break;
          case 2:
              if (enc1.isRight()){ del=del-30;if(del<=5){del=3;}  }
              if (enc1.isLeft()) { del=del+30;if(del>=6000){del=6000;}  } 
              if (enc1.isClick()){if(rainbow==false){rainbow=true;}else{rainbow=false;}}
              rVal = rVal + rDir;r=rVal;analogWrite(3,map(r,0,255,0,1));
              gVal = gVal + gDir;g=gVal;analogWrite(5,map(g,0,255,0,1));
              bVal = bVal + bDir;b=bVal;analogWrite(6,map(b,0,255,0,1));
              if (rVal >= 127 || rVal <= 0) {rDir = rDir * -1;}
              if (gVal >= 255 || gVal <= 0) {gDir = gDir * -1;}
              if (bVal >= 255 || bVal <= 0) {bDir = bDir * -1;}
              if (rainbow==false){r=0;g=0;b=0;}
              delayMicroseconds(del);analogWrite(3,0);analogWrite(5,0);analogWrite(6,0);
          break;
        }
    
        if(enc1.isHolded()){mode++;if(mode==3)mode=0;rainbow=false;buff=true;while(enc1.isHolded()){}}
        
        analogWrite(9,r);
        analogWrite(10,g);
        analogWrite(11,b);
    }
}
