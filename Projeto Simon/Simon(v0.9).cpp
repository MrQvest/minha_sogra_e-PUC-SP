//O que faz:
//cria uma sequencia aleatoria de 10 passos com 4 LEDs diferentes
//inicia mostrando apenas 1 cor da sequencia, entao aguarda input
//apos receber o mesmo numero de inputs da sequencia monstrada, adiciona mais 1 cor a sequencia mostrada
//utiliza um joystick (dois potenciometros) para determinar input
//agora com som!!!
//tempo entre cores diminui apos cada rodada
//bug de resetar arrumado

 /* 
  Tetris theme - (Korobeiniki) 
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

// change this to make the song slower or faster
int temp=400;   //old value was 144 

// change this to whichever pin you want to use
int buzzer = 12;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
  

  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,

};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes=sizeof(melody)/sizeof(melody[0])/2; 

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = (60000 * 4) / temp;

int divider = 0, noteDuration = 0;


/*
  Frequência das notas:
  Dó - 262 Hz
  Ré - 294 Hz
  Mi - 330 Hz
  Fá - 349 Hz
  Sol - 392 Hz
  Lá - 440 Hz
  Si - 494 Hz
  #Dó - 528 Hz
  */
  
#define VM 3
#define AM 7
#define VD 9
#define AZ 11
#define BUZZER 12

#define do 262
#define re 294
#define mi 330
#define fa 349
#define sol 392
#define la 440
#define si 494
#define do1 528

int cores[]={1,2,VM,AM,VD,AZ};
int sequencia[10]; //sequencia total de cores
int size = sizeof(sequencia) / sizeof(int);//guarda o numero de cores na sequencia

//int led_entradas[] = {3, 7, 9, 11}; //entradas dos leds
int led_entradas[] = {AZ, AM, VM, VD}; //entradas dos leds
int estado; //0 - monstrando | 1 - jogando | 2 - erro 

int indice; //indica qual a ultima posicao atual da sequencia de cores
int i; //contador
int contador_jogador;

//variavel de tempo
int tempo = 1000;

int xposition = 512;
int yposition = 512;
bool jogador = 1;

//classe botao
class Botao {
  int Down=false,Up=false,Pressed=false;
  int buttonPin;

  //Cópia do código:https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce/
  int buttonState;             // the current reading from the input pin
  int lastButtonState = LOW;   // the previous reading from the input pin

  // the following variables are unsigned longs because the time, measured in
  // milliseconds, will quickly become a bigger number than can be stored in an int.
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

  public:
  void setupBot(int p);
  int ButtonDown();
  int ButtonUp();
  int ButtonPressed();
  

  private:
  void leituraBotao() ;
};
  
  
void Botao::setupBot(int p) {
  buttonPin=p;
  pinMode(buttonPin, INPUT);
}
//Novas funcionalidades do botão
int Botao::ButtonDown() {//no momento que pressiona, uma vez

  leituraBotao(); 
  if(Down)
  {    
    Down=false;
    return true;
  }
  else
  {
    return false;
  }
}
int Botao::ButtonUp() {//no momento que solta, uma vez

  leituraBotao();
  if(Up)
  {
    Up=false;
    return true;
  }
  else
  {
    return false;
  }
}
int Botao::ButtonPressed() {//botão pressionado direto

  leituraBotao();
  if(Pressed)
  {
    return true;
  }
  else
  {
    return false; 
  }
  
}
void Botao::leituraBotao() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) 
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) 
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) 
      {
        Pressed=true;
        Down = true;
      }
      else
      {
        Pressed=false;
        Up=true;
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
//Fim Botao


void abertura() { // melodia de entrada e leds piscando
  
  int pisca = 100;
  boolean vez = false;
    
    // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
    //  for(int i=0; i<4; i++) digitalWrite(cores[i],HIGH); 
      noteDuration = (wholenote) / divider;   
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
  //    for(int i=0; i<4; i++) digitalWrite(cores[i],HIGH); 
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    for(int i=0; i<6; i++) digitalWrite(cores[i],HIGH);  //acende todos os led's ao tom da musica  - pisca
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);   
    for(int i=0; i<6; i++) digitalWrite(cores[i],LOW); //apaga todos os led's ao tom da musica - pisca
    delay(noteDuration);
    // stop the waveform generation before the next note.
    noTone(buzzer);
  }

}



void setup() {
  //LEDS
  pinMode(VM, OUTPUT);  ;; 
  pinMode(AM, OUTPUT);
  pinMode(VD, OUTPUT);
  pinMode(AZ, OUTPUT);
  
  //JOYSTICK JOGADOR 1
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(5,  INPUT);
  
  //LED JOGADOR 1
  pinMode(1, OUTPUT);
  
  //JOYSTICK JOGADOR 2
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(4,  INPUT);
  
  //LED JOGADOR 2
  pinMode(2, OUTPUT);
  
  //BUZZER
  pinMode(BUZZER, OUTPUT);

  //cria a sequencia de cores
  for(int i=0; i<=size; i++) {
    sequencia[i] = 0;
  }
  //inicializa os valores dos contadores
  i = 0;
  indice = 0;
  estado = 0;
  contador_jogador = 0;
  abertura();
}


void loop() {

  //ESTADO MOSTRANDO
  while(estado == 0)
  {
    //mostra cores ate i = indice
  while (i<=indice) 
    {
      
      digitalWrite(sequencia[i], HIGH);
      if(sequencia[i]==AZ) tone(BUZZER, 261);
      if(sequencia[i]==VD) tone(BUZZER, 293);
      if(sequencia[i]==AM) tone(BUZZER, 329);
      if(sequencia[i]==VM) tone(BUZZER, 349);
      
      delay(tempo); // Wait for 1000 millisecond(s)
      digitalWrite(sequencia[i], LOW);
      noTone(BUZZER);
      delay(tempo/2); // Wait for 500 millisecond(s)
      i++;
    }
    estado = 1;//trocar de estado -> jogando
  }
  
  //reset contador
  i = 0;

  //ESTADO JOGANDO
  while(estado == 1)
  {
    if(jogador == 1)
    {
      digitalWrite(1, HIGH);
      digitalWrite(2,  LOW);
      xposition = analogRead(A0);
      yposition = analogRead(A1);
    }
    else
    {
      digitalWrite(2, HIGH);
      digitalWrite(1,  LOW);
      xposition = analogRead(A3);
      yposition = analogRead(A2);
    }

    //BOTAO VERMELHO
    if(yposition > 700)
    {
      //coloca cor se sequencia vazia
      if(sequencia[contador_jogador] == 0)
        sequencia[contador_jogador] = VM;
                  
      //se errar vai para ESTADO ERRO
      if (sequencia[contador_jogador] != VM)estado = 2;//trocar de estado -> erro
      else
      {
        contador_jogador++;
        digitalWrite(VM, HIGH);
        tone(BUZZER, 349);
        delay(tempo);
        digitalWrite(VM, LOW);
        noTone(BUZZER);
        delay(tempo/2);
      }
    }
    //BOTAO AMARELO
    if(xposition > 700)
    {
      //coloca cor se sequencia vazia
      if(sequencia[contador_jogador] == 0)
        sequencia[contador_jogador] = AM;
                  
      //se errar vai para ESTADO ERRO
      if (sequencia[contador_jogador] != AM)estado = 2;//trocar de estado -> erro
      else
      {
        contador_jogador++;
        digitalWrite(AM, HIGH);
        tone(BUZZER, 329);
        delay(tempo);
        digitalWrite(AM, LOW);
        noTone(BUZZER);
        delay(tempo/2);
      }
    }
    
    //BOTAO VERDE
    if(yposition < 300)
    {
      //coloca cor se sequencia vazia
      if(sequencia[contador_jogador] == 0)
        sequencia[contador_jogador] = VD;
                  
      //se errar vai para ESTADO ERRO
      if (sequencia[contador_jogador] != VD)estado = 2;//trocar de estado -> erro
      else
      {
        contador_jogador++;
        digitalWrite(VD, HIGH);
        tone(BUZZER, 293);
        delay(tempo);
        digitalWrite(VD, LOW);
        noTone(BUZZER);
        delay(tempo/2);
      }
    }

  //BOTO AZUL
    if(xposition < 300)
    {
      //coloca cor se sequencia vazia
      if(sequencia[contador_jogador] == 0)
        sequencia[contador_jogador] = AZ;
                  
      //se errar vai para ESTADO ERRO
      if (sequencia[contador_jogador] != AZ)estado = 2;//trocar de estado -> erro
      else
      {
        contador_jogador++;
        digitalWrite(AZ, HIGH);
        tone(BUZZER, 261);
        delay(tempo);
        digitalWrite(AZ, LOW);
        noTone(BUZZER);
        delay(tempo/2);
      }
    }
    
    //sair da condicao jogando se completou a rodada
    if (contador_jogador>indice)
    {
      indice++;
      if(indice>=size)estado = 3; //trocar de estado -> vitoria
      else estado = 0;//trocar de estado -> mostrando
      contador_jogador = 0;
      tempo = tempo*0.9;
      jogador = !jogador;
    }
    else if(indice>=size)estado = 3;    
  }

  //ESTADO ERRO
  while(estado == 2)
  {
    //cria uma nova sequencia de cores
    for(int i=0; i<=size; i++)
    {
      sequencia[i] = led_entradas[random(0,4)];
    }
    indice = 0;
    tempo = 1000;
    contador_jogador = 0;
    jogador = 1;

    for(int j=0;j<5;j++)
    {
      digitalWrite(VM, HIGH);
      digitalWrite(AM, HIGH);
      digitalWrite(VD, HIGH);
      digitalWrite(AZ, HIGH);
      tone(BUZZER, 261);
      delay(200);
      digitalWrite(VM, LOW);
      digitalWrite(AM, LOW);
      digitalWrite(VD, LOW);
      digitalWrite(AZ, LOW);
      noTone(BUZZER);
      delay(200);
    }
    delay (300);
    estado = 0;    
  }
  
  //ESTADO VITORIA
  while(estado == 3)
  {
    digitalWrite(VM, HIGH);
    digitalWrite(AM, LOW);
    digitalWrite(VD, HIGH);
    digitalWrite(AZ, LOW);
    delay(500);
    digitalWrite(VM, LOW);
    digitalWrite(AM, HIGH);
    digitalWrite(VD, LOW);
    digitalWrite(AZ, HIGH);
    delay(500);
  }



  
}
