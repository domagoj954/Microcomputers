/*
 * arduino_piano.cpp
 *
 * Created: 26/12/2021 21:47:12
 * Author : Domagoj
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "PROJECT/project.h"
#include "ADC/adc.h"
#include "LCD/lcd.h"
#include "LCD/i2c.h"
#include "INTERRUPT/interrupt.h"

int note[8] = {261, 293, 329, 349, 392, 440, 494, 523}; //frekvencija nota za buzzer (C4, D4, E4, F4, G4, A4, B4, C5)
int newNote[100] = {}; // novo polje u koje ce se spremati frekvencija nota u odredenom redoslijedu
int i; 

ISR(INT0_vect) { //prekidna rutina za vanjski prekid INT0
    if(get_pin(PIND, PD2) == 1) { //ako je pin PD2 u logi?koj jedinici
        lcd_clear(); //ocisti LCD
        lcd_write("PAUZA"); //ispisi "PAUZA" na LCD-u
    }
}

ISR(INT1_vect) { //prekidna rutina za vanjski prekid INT1
   if(get_pin(PIND, PD3) == 1) { //ako je pin PD3 u logi?koj jedinici
        lcd_clear(); //ocisti LCD
        lcd_write("PREKID"); //ispisi "PREKID" na LCD-u
        PORTB |= (1 << PB4); //upali crvenu ledicu
        PORTB &= ~ (1 << PB1); // ugasi zutu ledicu
        PORTB &= ~ (1 << PB2); //ugasi zelenu ledicu
    } 
    if(get_pin(PIND, PD3) == 0){  //ako je pin PD3 u logi?koj nuli
        lcd_clear(); //ocisti LCD
        lcd_write("NASTAVITE"); //ispisi poruku
    }   
}

ISR (PCINT0_vect) {//prekidna rutina za vanjski prekid PCINT
       lcd_clear(); //ocisti LCD
       lcd_write("GOTOVO"); //ispisi poruku
        _delay_ms(500);
       lcd_clear();
       _delay_ms(500);
      lcd_write("POTREBAN RESET"); //ispisi poruku
      PORTB |= (1 << PB5); //upali plavu ledicu
      PORTB &= ~ (1 << PB2); //ugasi zelenu ledicu
}    
 

void init(){
    
	//definiranje izlaznih pinova
	
	DDRB |= (1 << PB0); //buzzer
	DDRB |= (1 << PB1); //zuta ledica
	DDRB |= (1 << PB2); //zelena ledica
    DDRB |= (1 << PB4); //crvena ledica
    DDRB |= (1 << PB5); //plava ledica
    
	adc_init () ;  //inicijalizacija za adc 
    i2c_init();  // innicijalizacija za i2c
    lcd_init(); // inicijalizacija za lcd
    
    //inicijalizacija za I2C (PCF8574)
    i2c_start(0x40);
    i2c_byte(0xF0);
    i2c_stop();
    
    int0_enable() ; //omoguci prekid  za INT0
    int0_set_rising_falling_edge() ; //oba brida generiraju prekid INT0

    int1_enable() ; //omoguci prekid za INT1
    int1_set_rising_falling_edge () ; //rastuci i padajuci brid generira prekid INT1
	interrupt_enable(); //omoguci globalni prekid
	
    // konfiguriranje ulaza PD0 i PD1
	DDRD &= ~((1 << PD0) | (1 << PD1));
	PORTD |= (1 << PD0) | (1 << PD1);
 
    pcint_enable(); //omoguci PCINT prekide
    pcint_pin_enable(PCINT3) ; //omoguci prekid na pinu PCINT3
}


void play(float U_ADC0){ //funkcija za sviranje satipkalima, argument funkcije je napon na pinu ADC0 (A0)
	
             
           if(get_pin(PIND, PD3) == 0){ //ako je pin PD3 u logi?koj nuli
               PORTB &= ~ (1 << PB4); //ugasi crvenu ledicu

    
			if(U_ADC0 == 0){ //ako nije pritisnuto niti jedno tipkalo na kanalu A0, upaljena je zuta ledica
				PORTB |= (1 << PB1); //upali zutu ledicu
				PORTB &= ~ (1 << PB2); //ugasi zelenu ledicu

			}else{
                PORTB &= ~ (1 << PB1); //ugasi zutu ledicu
				_delay_ms (10); //delay od 10 ms
				PORTB |= (1 << PB2); //ako je pritisnuto bilo koje tipkalo na kanalu A0, upaljena je zelena ledica
            }

			if(U_ADC0 < 5.00 && U_ADC0 >= 4.80) { // ako pritisnuto tipkalo odgovara ovom naponu
				BUZZ (0.1 , note[0]) ; _delay_ms (100) ;  //ukljuci buzzer
                lcd_clear(); // ocisti LCD display
                lcd_write("C4");  // ispisi na lcd koja nota odgovara pritisnutom tipkalu 
                newNote[i] = note[0]; // spremi vrijednost note u novo polje
                i++; // povecaj indeks polja za 1
			}
            
            //isti slucaj za ostale kao i za prethodni
			
     	    if(U_ADC0 < 4.80 && U_ADC0 >= 4.75){  
				BUZZ (0.1 , note[1]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("D4");
                newNote[i] = note[1];
                i++;
			}
			
		    if(U_ADC0 < 4.72 && U_ADC0 >= 4.65){
				BUZZ (0.1 , note[2]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("E4");
                newNote[i] = note[2];
                i++;
			}
			
		    if(U_ADC0 < 4.60 && U_ADC0 >= 4.50){
				BUZZ (0.1 , note[3]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("F4");
                newNote[i] = note[3];
                i++;
			}
			
			if(U_ADC0 < 4.20 && U_ADC0 >= 4.05){
				BUZZ (0.1 , note[4]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("G4");
                newNote[i] = note[4];
                i++;
			}
			
			if(U_ADC0 < 3.80 && U_ADC0 >= 3.70){
				BUZZ (0.1 , note[5]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("A4");
                newNote[i] = note[5];
                i++;
			}
			
			if(U_ADC0 < 3.55 && U_ADC0 >= 3.30){
				BUZZ (0.1 , note[6]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("B4");
                newNote[i] = note[6];
                i++;
			}
			
			if(U_ADC0 < 2.55 && U_ADC0 >= 2.45){
				BUZZ (0.1 , note[7]) ; _delay_ms (100) ;
                lcd_clear();
                lcd_write("C5");
                newNote[i] = note[7];
                i++;

         }		          
     }
}

int main(void){ 
    
	init(); //inicijalizacija 
 
    lcd_clear(); //ocisti LCD
    lcd_write("Arduino piano"); //ispisi poruku na LCD-u


	uint16_t ADC_0 ; // analogni pin A0
	float U_ADC0 ; // napon na pinu ADC0 (A0)
	const float V_REF = 5.0; // AVCC je referentni napon
	float y[2] = {0 , 0}; // {y[k-1] , y[k]}
	uint8_t k = 1; // varijabla k
    
    unsigned int arrSize = sizeof(newNote)/sizeof(newNote[0]); //duljina novog polja 

	while(1){

        ADC_0 = adc_read(ADC0); // u ADC_0 spremljene vrijednosti analogno-digitalne pretvorbe sa kanala ADC0
        y[k] = 0.0 * y[k - 1] + 1.0 * ADC_0 ; //digitalni filter, potrebene izmjene
        U_ADC0 = y[k] * V_REF / 1023.0; //racunanje vrijednosti napona
        y[k-1] = y[k]; // prethodno mjerenje sada je trenutno
        
       	play(U_ADC0); //funkcija za sviranje
          
        if(get_pin(PIND, PD3) == 0){//ako je pin PD3 u logi?koj nuli
            if(U_ADC0 < 1.7 && U_ADC0 >= 1.4){ //ako je pritisnuto tipkalo 9
                lcd_clear();//ocisti LCD
                for(unsigned int i = 0; i < arrSize; i++){ //za raspon velicine novog polja
                BUZZ (0.1 , newNote[i]) ; _delay_ms (200) ; //ukljuci buzzer                  
          
                }            
            }                     
        }                               
  }   
}        
	
//ako se na kraju upali plava ledica i zuta ledica kada sezavrsi petlja za newNote
//to znaci da se i dalje moze svirati ali je potreban reset



