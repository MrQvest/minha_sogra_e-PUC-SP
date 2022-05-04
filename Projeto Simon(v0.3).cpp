//O que faz:
//cria uma sequencia aleatoria de 10 passos com 4 LEDs diferentes
//inicia mostrando apenas 1 cor da sequencia, entao aguarda input
//apos receber o mesmo numero de inputs da sequencia monstrada, adiciona mais 1 cor a sequencia mostrada
//qualquer um does quatro botoes funciona

#define VM 3
#define VM_BUT 2

#define AM 7
#define AM_BUT 6

#define VD 9
#define VD_BUT 8

#define AZ 11
#define AZ_BUT 10

int sequencia[10]; //sequencia total de cores
int led_entradas[4] = {3, 7, 9, 11}; //entradas dos leds
int jogando; //se 1, esta esperando input 

int indice; //indica qual a ultima posicao atual da sequencia de cores
int i; //contador
int contador_jogador;

//VERMELHO DEBOUNCE
int buttonStateVM = LOW;             // the current reading from the input pin
int lastButtonStateVM = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTimeVM = 0;  // the last time the output pin was toggled

//AMARELO DEBOUNCE
int buttonStateAM = LOW;             // the current reading from the input pin
int lastButtonStateAM = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTimeAM = 0;  // the last time the output pin was toggled

//VERDE DEBOUNCE
int buttonStateVD = LOW;             // the current reading from the input pin
int lastButtonStateVD = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTimeVD = 0;  // the last time the output pin was toggled

//AZUL DEBOUNCE
int buttonStateAZ = LOW;             // the current reading from the input pin
int lastButtonStateAZ = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTimeAZ = 0;  // the last time the output pin was toggled

int reading;
unsigned long debounceDelay = 100;    // the debounce time; increase if the output flickers

void setup()
{
  pinMode(VM, OUTPUT);
  pinMode(AM, OUTPUT);
  pinMode(VD, OUTPUT);
  pinMode(AZ, OUTPUT);
  
  pinMode(VM_BUT, INPUT);
  pinMode(AM_BUT, INPUT);
  pinMode(VD_BUT, INPUT);
  pinMode(AZ_BUT, INPUT);
  //inicializa com uma seed aleatoria da entrada 0 (desconectada)
  randomSeed(analogRead(0));

  //cria a sequencia de cores
  for(int i=0; i<=10; i++)
  {
    sequencia[i] = led_entradas[random(0,4)];
  }
  //inicializa os valores dos contadores
  i = 0;
  indice = 0;
  jogando = 0;
  contador_jogador = 0;

}

void loop()
{

  //ESTADO MOSTRANDO
  while(jogando == 0)
  {
    //mostra cores ate i = indice
	while (i<=indice) 
    {    
      	digitalWrite(sequencia[i], HIGH);
  		delay(1000); // Wait for 1000 millisecond(s)
 		digitalWrite(sequencia[i], LOW);
  		delay(500); // Wait for 500 millisecond(s)
      	i++;
    }
    jogando = 1;
  }
  
  //reset contador
  i = 0;

  //ESTADO JOGANDO
  while(jogando == 1)
  {
  	//DEBOUNCE VERMELHO
  	reading = digitalRead(VM_BUT);
  	if (reading != lastButtonStateVM)lastDebounceTimeVM = millis();// reset the debouncing timer
  
  	if ((millis() - lastDebounceTimeVM) > debounceDelay) 
    {
    	// whatever the reading is at, it's been there for longer than the debounce
    	// delay, so take it as the actual current state:

    	// if the button state has changed:
    	if (reading != buttonStateVM) 
        {
      		buttonStateVM = reading;

      		// only toggle the change if the new button state is HIGH
      		if (buttonStateVM == HIGH) 
            {
              contador_jogador++;
              digitalWrite(VM, HIGH);
              delay(1000);
              digitalWrite(VM, LOW);
              delay(500);
      		}
    	}
  	}
    lastButtonStateVM = reading;
    
   	//DEBOUNCE AMARELO
  	reading = digitalRead(AM_BUT);
  	if (reading != lastButtonStateAM)lastDebounceTimeAM = millis();// reset the debouncing timer
  
  	if ((millis() - lastDebounceTimeAM) > debounceDelay) 
    {
    	// whatever the reading is at, it's been there for longer than the debounce
    	// delay, so take it as the actual current state:

    	// if the button state has changed:
    	if (reading != buttonStateAM) 
        {
      		buttonStateAM = reading;

      		// only toggle the change if the new button state is HIGH
      		if (buttonStateAM == HIGH) 
            {
              contador_jogador++;
              digitalWrite(AM, HIGH);
              delay(1000);
              digitalWrite(AM, LOW);
              delay(500);
      		}
    	}
  	}
    lastButtonStateAM = reading;   
    
    //DEBOUNCE VERDE
  	reading = digitalRead(VD_BUT);
  	if (reading != lastButtonStateVD)lastDebounceTimeVD = millis();// reset the debouncing timer
  
  	if ((millis() - lastDebounceTimeVM) > debounceDelay) 
    {
    	// whatever the reading is at, it's been there for longer than the debounce
    	// delay, so take it as the actual current state:

    	// if the button state has changed:
    	if (reading != buttonStateVD) 
        {
      		buttonStateVD = reading;

      		// only toggle the change if the new button state is HIGH
      		if (buttonStateVD == HIGH) 
            {
              contador_jogador++;
              digitalWrite(VD, HIGH);
              delay(1000);
              digitalWrite(VD, LOW);
              delay(500);
      		}
    	}
  	}
    lastButtonStateVD = reading;
    
   	//DEBOUNCE AZUL
  	reading = digitalRead(AZ_BUT);
  	if (reading != lastButtonStateAZ)lastDebounceTimeAZ = millis();// reset the debouncing timer
  
  	if ((millis() - lastDebounceTimeAZ) > debounceDelay) 
    {
    	// whatever the reading is at, it's been there for longer than the debounce
    	// delay, so take it as the actual current state:

    	// if the button state has changed:
    	if (reading != buttonStateAZ) 
        {
      		buttonStateAZ = reading;

      		// only toggle the change if the new button state is HIGH
      		if (buttonStateAZ == HIGH) 
            {
              contador_jogador++;
              digitalWrite(AZ, HIGH);
              delay(1000);
              digitalWrite(AZ, LOW);
              delay(500);
      		}
    	}
  	}
    lastButtonStateAZ = reading;
    //sair da condicao jogando
    if (contador_jogador>indice)
    {
      jogando = 0;
      indice++;
      contador_jogador = 0;
    }
  }

}
