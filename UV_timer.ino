
#define A    4
#define B    0
#define C    14
#define D    12
#define E    11
#define F    3
#define G    15
#define DOT  13
#define D4   5
#define D3   2
#define D2   1
#define D1   16
#define B_plus   8
#define B_minus  9
#define B_start_stop 10
#define buz 6
#define led_a 7

int count_d;
uint32_t times;
uint32_t timer_t = 0, timer_plus, timer_minus, tb_p, tb_m, timer_led;
boolean b_p, b_m, b_ss, led_st, led_t = true;
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DOT, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(led_a, OUTPUT);
}

void loop() {
  d_swich();
  button();
  digitalWrite(led_a, led_st);
  if(count_d == 3 && led_t){
    digitalWrite(DOT, LOW);
  }else{
    digitalWrite(DOT, HIGH);
  }

}
void digits(int digit){
    switch (digit) {
        case 1: //B,C
        digitalWrite(A, HIGH); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH);
        break;
        case 2: //A,B,G,E,D
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, LOW);
        break;
        case 3: //A,B,G,C,D
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, LOW);
        break;
        case 4: //F,G,B,C
        digitalWrite(A, HIGH); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW);
        break;
        case 5: //A,F,G,C,D
        digitalWrite(A, LOW); 
        digitalWrite(B, HIGH); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW);
        break;
        case 6: //A,F,G,C,D,E
        digitalWrite(A, LOW); 
        digitalWrite(B, HIGH); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW);
        break;
        case 7: //A,B,C
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH);
        break;
        case 8: //A,B,C,D,E,F,G
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW);
        break;
        case 9: //A,B,C,D,F,G
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW);
        break;
        case 0: //A,B,C,D,E,F
        digitalWrite(A, LOW); 
        digitalWrite(B, LOW); 
        digitalWrite(C, LOW); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, HIGH);
        break;

  }

}
void d_swich(){
  uint32_t t1 = millis();
  if(t1 - times > 1){
     times = t1;
     count_d++;
     if(count_d > 5){
       count_d = 0;
     }
  }
 int times_a[4];
 int timess = timer_t;
 int timeseconds = (timess % 60);
 int timeminuts = ((timess  % 3600) / 60);
 times_a[0] = timeseconds %10;
 times_a[1] = timeseconds /10;
 times_a[2] = timeminuts %10;
 times_a[3] = timeminuts /10;
  switch (count_d) {
           case 0:
           digitalWrite(D1,LOW);
           digitalWrite(D2,LOW);
           digitalWrite(D3,LOW);
           digitalWrite(D4,LOW);
           break;
           case 1:
           digits(times_a[0]);
           digitalWrite(D1,HIGH);
           break;
           case 2:
           digitalWrite(D1,LOW);
           digits(times_a[1]);
           digitalWrite(D2,HIGH);
       
           break;
           case 3:
           digitalWrite(D2,LOW);
           digits(times_a[2]);
           digitalWrite(D3,HIGH);
           break;
           case 4:
           digitalWrite(D3,LOW);
           digits(times_a[3]);
           digitalWrite(D4,HIGH);
           break;
           case 5:
           digitalWrite(D1,LOW);
           digitalWrite(D2,LOW);
           digitalWrite(D3,LOW);
           digitalWrite(D4,LOW);
           break;

    }

}
void button(){
   if(digitalRead(B_plus) && !b_p && !digitalRead(B_minus)){
         timer_t++;
         b_p = true;
         tb_p = millis();
  }
    if(!digitalRead(B_plus) && b_p){ b_p = false; }
    
    if(digitalRead(B_minus) && !b_m && !digitalRead(B_plus)){
        timer_t--;
        b_m = true;
        tb_m = millis();
  }
    if(!digitalRead(B_minus) && b_m){ b_m = false; }

         if(millis() - tb_p > 2000 && b_p && !b_m){
             uint32_t t1 = millis();
             if(t1 - timer_plus > 100 ){
                    timer_plus = t1;
                    timer_t++;
                    }
                  }
                  
         if(millis() - tb_m > 2000 && b_m && !b_p){
             uint32_t t1 = millis();
             if(t1 - timer_minus > 100 ){
                    timer_minus = t1;
                    timer_t--;
                    }
                  }

    if(digitalRead(B_start_stop) && !b_ss ){
           b_ss = true;
           led_st = !led_st;
     }
    if(!digitalRead(B_start_stop) && b_ss){ b_ss = false; }    

             uint32_t t1 = millis();
             if(t1 - timer_led >= 1000 && led_st){
                    timer_led = t1;
                    timer_t--;
                    if(timer_t == 0){
                      led_st = false;
                        }
                  }
}
