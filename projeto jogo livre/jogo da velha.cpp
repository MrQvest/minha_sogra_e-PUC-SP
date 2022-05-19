//inclusão de livrarias
#include <TouchScreen.h>
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>

//definição de pinos analógicos
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

//definição das cores
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//pinos analógicos
#define YP A2  
#define XM A3 
//pinos digitais
#define YM 8   
#define XP 9   

//uso de livrarias
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 400);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


//x = 0 :blue
//x = 1 :red
int x = 0;
int rturn = 0;

//definição das instâncias jogador 1 e 2
int a;
int ab;
int b;
int bb;
int c;
int cb;
int d;
int db;
int e; 
int eb;
int f;
int fb;
int g;
int gb;
int h;
int hb;
int i;
int ib;

void setup() {
  
//limpar tela para inicializar o resto
tft.reset();
tft.begin(0x9341);
tft.fillScreen(BLACK);
tft.setRotation(1);

//inicializar
Serial.begin(9600);

tft.setCursor(60, 110);
tft.setTextColor(RED);
tft.setTextSize(3);
tft.println("Tic Tac Toe");
delay(2000);

tft.setCursor(113, 154);
tft.setTextColor(CYAN);
tft.setTextSize(1);
tft.println("by MisterBotBreak");

delay(2000);

tft.setCursor(5, 178);
tft.setTextColor(GREEN);
tft.setTextSize(1);
tft.println("In this game, there are two players : Player BLUE");
tft.setCursor(5, 187);
tft.println("and Player RED. Each turn, they can put pads on a");
tft.setCursor(5, 196);
tft.println("grid. You win once three of your pads are aligned.");

delay(9000);


tft.fillScreen(BLACK);

tft.drawLine(113, 10, 113, 230, WHITE);
tft.drawLine(208, 10, 208, 230, WHITE);

tft.drawLine(30, 80, 290, 80, WHITE);
tft.drawLine(30, 160, 290, 160, WHITE);

  pinMode(13, OUTPUT);

}


void loop() {
  
returning: //usado para recomeçar o jogo

if(rturn==1){ //se rturn==1, resetar
tft.fillScreen(BLACK);
tft.drawLine(113, 10, 113, 230, WHITE);
tft.drawLine(208, 10, 208, 230, WHITE);

tft.drawLine(30, 80, 290, 80, WHITE);
tft.drawLine(30, 160, 290, 160, WHITE);
rturn = 0;
x = 0;
 
 //resetar instâncias jogador
 a = 0;
 ab = 0;
 b = 0;
 bb = 0;
 c = 0;
 cb = 0;
 d = 0;
 db = 0;
 e = 0;
 eb = 0;
 f = 0;
 fb = 0;
 g = 0;
 gb = 0;
 h = 0;
 hb = 0;
 i = 0; 
 ib = 0;
  }
  
  
digitalWrite(13, HIGH);
 TSPoint p = ts.getPoint();	//TSPointp=ts.getPoint(); stores the length (x), width (y) and compression (z) in the p object.
 digitalWrite(13, LOW);
 
 if (p.z > ts.pressureThreshhold) { //se tela for apertada
    
pinMode(XM, OUTPUT);
pinMode(YP, OUTPUT);
  
   if(p.y < 380){ //?
    
    if(p.x < 400){ //?
	
        if(x==0){ //se for vez do jogador 1
        tft.fillCircle(70, 45, 25, BLUE);
        x=x+1;
        a = 1;
        delay(10);
        }
        else if(x==1){ //se não, se for vez do jogador 2
        tft.fillCircle(70, 45, 25, RED);
        x=x-1;
        ab = 1;
        delay(10);
        }
        }
      
    

 else if(p.x < 650 && p.x > 400){ //?
 
        if(x==0){ //se vez jogador 1
        tft.fillCircle(160, 45, 25, BLUE);
        x=x+1;
        b = 1;
        delay(10);
        }
        else if(x==1){ //se vez jogador 2
        tft.fillCircle(160, 45, 25, RED);
        x=x-1;
        bb = 1;
        delay(10);
        }
       
        }
      
    

  else if(p.x > 650){ //?
  
        if(x==0){ //se jogador 1
        tft.fillCircle(250, 45, 25, BLUE);
        x=x+1;
        c = 1;
        delay(10);
        }
        else if(x==1){ //se jogador 2
        tft.fillCircle(250, 45, 25, RED);
        x=x-1;
        cb = 1;
        delay(10);
        }
       
        }
      }
   
 
 
  else if(p.y > 380 && p.y < 650){ //?
  
   if(p.x < 400){ //?
   
        if(x==0){ //se jogador 1
        tft.fillCircle(70, 120, 25, BLUE);
        x=x+1;
        d = 1;
        delay(10);
        }
        else if(x==1){ //se jogador 2
        tft.fillCircle(70, 120, 25, RED);
        x=x-1;
        db = 1;
        delay(10);
        }
       
      }

      
     else if(p.x < 650 && p.x > 400){ //?
        if(x==0){
        tft.fillCircle(160, 120, 25, BLUE);
        x=x+1;
        e = 1;
        delay(10);
        }
        else if(x==1){
        tft.fillCircle(160, 120, 25, RED);
        x=x-1;
        eb = 1;
        delay(10);
        }
     
        }
      

       else if(p.x > 650){ //?
        if(x==0){
        tft.fillCircle(250, 120, 25, BLUE);
        x=x+1;
        f = 1;
        delay(10);
        }
        else if(x==1){
        tft.fillCircle(250, 120, 25, RED);
        x=x-1;
        fb = 1;
        delay(10);
        }
        
        }
      
 }


  else if(p.y > 650){ //?

 if(p.x < 400){     
        if(x==0){
        tft.fillCircle(70, 195, 25, BLUE);
        x=x+1;
        g = 1;
        delay(10);
        }
        else if(x==1){
        tft.fillCircle(70, 195, 25, RED);
        x=x-1;
        gb = 1;
        delay(10);
        }
       
      }

      
     else if(p.x < 650 && p.x > 400){ //?
        if(x==0){
        tft.fillCircle(160, 195, 25, BLUE);
        x=x+1;
        h = 1;
        delay(10);
        }
        else if(x==1){
        tft.fillCircle(160, 195, 25, RED);
        x=x-1;
        hb = 1;
        delay(10);
        }
     
        }
      

       else if(p.x > 650){ //?
        if(x==0){
        tft.fillCircle(250, 195, 25, BLUE);
        x=x+1;
        i = 1;
        delay(10);
        }
        else if(x==1){
        tft.fillCircle(250, 195, 25, RED);
        x=x-1;
        ib = 1;
        delay(10);
        }
        
        }
 
 }

 delay(500);
 
//definição de todas as condições de vitória
 if(a==1 && b==1 && c==1){ 
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 

 
    } 
    if(d==1 && e==1 && f==1){ 
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 
    } 
if(g==1 && h==1 && i==1){
  tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 
    } 

if(a==1 && d==1 && g==1){
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 
    } 
if(b==1 && e==1 && h==1){
  tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 
    } 
if(c==1 && f==1 && i==1){
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
    }

if(c==1 && e==1 && g==1){
 tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);
tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
    }
   if(a==1 && e==1 && i==1){
  tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(GREEN);
tft.setTextSize(2);
tft.println("Player 1 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
    }

 if(ab==1 && bb==1 && cb==1){
 tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning; 
 }
  if(db==1 && eb==1 && fb==1){
   tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
  }
  if(gb==1 && hb==1 && ib==1){
   tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
  }


  if(ab==1 && db==1 && gb==1){
  tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000); 

 tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
  }
if(bb==1 && eb==1 && hb==1){
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
}
if(cb==1 && fb==1 && ib==1){
tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000); 

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
}

if(cb==1 && eb==1 && gb==1){
 tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000); 

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;

}
   if(ab==1 && eb==1 && ib==1){
   tft.fillScreen(BLACK);
tft.setCursor(80, 110);
tft.setTextColor(YELLOW);
tft.setTextSize(3);
tft.println("Victory !");
tft.setCursor(72, 140);
tft.setTextColor(RED);
tft.setTextSize(2);
tft.println("Player 2 Win !");
delay(3000);

tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
 }

//definição das condições de empate
 if(a||ab==1){
  if(b||bb==1){
    if(c||cb==1){
      if(d||db==1){
        if(e||eb==1){
          if(f||fb==1){
           if(g||gb==1){
            if(h||hb==1){
              if(i||ib==1){
tft.fillScreen(BLACK);                
tft.setCursor(65, 100);
tft.setTextColor(GREEN);
tft.setTextSize(3);
tft.println("No winner."); 
delay(2000);               
tft.fillScreen(BLACK);
tft.setCursor(20, 110);
tft.setTextColor(CYAN);
tft.setTextSize(2);
tft.println("Ready for another game ?");
delay(2000);
tft.setCursor(100, 140);
tft.setTextColor(MAGENTA);
tft.setTextSize(2);
tft.println("Loading");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading.");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading..");
delay(800);
tft.setCursor(100, 140);
tft.println("Loading...");
delay(800);
rturn = 1;
goto returning;
              }
            }
          }
        }
      }
    } 
  }
 }
 }
 
}
}
