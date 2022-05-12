//O que faz:
//cria uma sequencia aleatoria de 10 passos com 4 LEDs diferentes
//inicia mostrando apenas 1 cor da sequencia, entao aguarda input
//apos receber o mesmo numero de inputs da sequencia monstrada, adiciona mais 1 cor a sequencia mostrada
//o botao coreto precisa ser apertado
//agora com som!!!
//tempo entre cores diminui apos cada rodada
//bug de resetar arrumado

// C++ code
//
#define VM 3
#define AM 7
#define VD 9
#define AZ 11

#define BUZZER 12

//classe botao
class Botao
{
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
  
  
void Botao::setupBot(int p) 
{
  buttonPin=p;
  pinMode(buttonPin, INPUT);
}
//Novas funcionalidades do botão
int Botao::ButtonDown()//no momento que pressiona, uma vez
{
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
int Botao::ButtonUp()//no momento que solta, uma vez
{
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
int Botao::ButtonPressed()//botão pressionado direto
{
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
void Botao::leituraBotao() 
{
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

int sequencia[10]; //sequencia total de cores
int size = sizeof(sequencia) / sizeof(int);//guarda o numero de cores na sequencia

int led_entradas[4] = {3, 7, 9, 11}; //entradas dos leds
int estado; //0 - monstrando | 1 - jogando | 2 - erro 

int indice; //indica qual a ultima posicao atual da sequencia de cores
int i; //contador
int contador_jogador;

//variavel de tempo
int tempo = 1000;
Botao AZ_BUT, VD_BUT, AM_BUT, VM_BUT;
void setup()
{
  pinMode(VM, OUTPUT);
  pinMode(AM, OUTPUT);
  pinMode(VD, OUTPUT);
  pinMode(AZ, OUTPUT);

  AZ_BUT.setupBot(10);
  VD_BUT.setupBot(8);
  AM_BUT.setupBot(6);
  VM_BUT.setupBot(2);

  
  pinMode(BUZZER, OUTPUT);
  
  //inicializa com uma seed aleatoria da entrada 0 (desconectada)
  randomSeed(analogRead(0));

  //cria a sequencia de cores
  for(int i=0; i<=size; i++)
  {
    sequencia[i] = led_entradas[random(0,4)];
  }
  //inicializa os valores dos contadores
  i = 0;
  indice = 0;
  estado = 0;
  contador_jogador = 0;

}

void loop()
{

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
    if(VM_BUT.ButtonDown())
    {
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
    
   	if(AM_BUT.ButtonDown())
    {
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
    
    if(VD_BUT.ButtonDown())
    {
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

   	if(AZ_BUT.ButtonDown())
    {
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
