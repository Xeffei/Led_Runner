  int sure;
  int mesafe;
  int trigger = 8;
  int echo = 9;

  
  void abc(){
    digitalWrite(trigger, HIGH);
    digitalWrite(trigger, LOW);
    sure=pulseIn(echo, HIGH);
    mesafe=(sure/2)/29.1;
 }

 
#define F_CPU 16000000ul
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>



class engel{
  public:
    int x,y;
};
  
int hareket (int x){
  return 2*x;
}

int araba (){
  int a=rand()%5;
  return a;
}

int main(void){

    
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
  
  int k =2;
  
  DDRC=0xFF;
  DDRD=0xFF;

  
  engel a;           //engellerin koordinatları random şekilde belirlenecek
  a.x=0b11111110;
  a.y=1;
  engel b;
  b.x=0b11111101;
  b.y=8;
  
  engel c;
  c.x=0b11111011;
  c.y =32;
  engel d;
  d.x=0b11110111;
  d.y=1;
  
  engel e;
  e.x=0b11101111;
  d.y=1;
  


    while (1) {
    int e1x= a.x;
    int e2x = b.x;
    int e3x = c.x;
    
    int e1y = a.y;
    int e2y = b.y;
    int e3y = c.y;
 
    while(1){
      int delay2 = 1;
      int i=0;
      while(i<100){
        PORTC = e1x;
        PORTD = e1y;
        _delay_ms(delay2);
        
        PORTD = e2y;
        PORTC = e2x;
         _delay_ms(delay2);
       
        PORTC = e3x;
        PORTD = e3y;
        _delay_ms(delay2);
        i++;
      }

    e1y= hareket(e1y);
    e2y= hareket(e2y);
    e3y =hareket(e3y);
   
    
    //uzaklık sensörü
    
    abc();
  int car;
  if (mesafe<4 & mesafe > 0){
    car = 0b11101111;
    }
  else if (mesafe < 6 & mesafe >= 4){
    
    car = 0b11110111;
    }
   else if (mesafe < 8 & mesafe >=6){
   car = 0b11111011;
   }
   else if (mesafe < 10 & mesafe >= 8 ){
   car = 0b11111101;
   }
   else if (mesafe < 16 & mesafe >=10 ){
   car=0b11111110;
   }




    
    
    
    
    
    //çarpışma

    
    if (e1y==128 && e1x==car){
      PORTC=0;
      PORTD=0xFF;
      
      _delay_ms(4000);
    }
    if (e2y==128 && e2x==car){
      PORTC=0;
      PORTD=0xFF;
      
      _delay_ms(4000);
    }
    if (e3y==128 && e3x==car){
      PORTC=0;
      PORTD=0xFF;
      
      _delay_ms(4000);
    }
    
    //yeni araba
    
    if(e1y==256){
      int i = araba();
      e1y = 1;
      if (i==0){
        e1x=a.x;
      }
      else if (i==1){
        e1x = b.x;
      }
      else if (i==2){
        e1x = c.x;
      }
      else if (i==3){
        e1x = d.x;
      }
      else if (i==4){
        e1x = e.x;
      }
      
    }
    if(e2y==256){
      int i = araba();
      e2y = 1;
      if (i==0){
        e2x=a.x;
      }
      else if (i==1){
        e2x = b.x;
      }
      else if (i==2){
        e2x = c.x;
      }
      else if (i==3){
        e2x = d.x;
      }
      else if (i==4){
        e2x = e.x;
      }
    
  }
    if(e3y==256){
      int i = araba();
      e3y = 1;
      if (i==0){
        e3x=a.x;
      }
      else if (i==1){
        e3x = b.x;
      }
      else if (i==2){
        e3x = c.x;
      }
      else if (i==3){
        e3x = d.x;
      }
      else if (i==4){
        e3x = e.x;
      }
    }
    }
  }
}
