#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/interrupt.h>

void interrupt_enable(){
	sei();
}

void interrupt_disable(){
	cli();
}	


/*******************************************************/
/*************************INT0**************************/

void int0_enable(){
	EIMSK |= (1 << INT0);
}

void int0_disable(){
	EIMSK &= ~(1 << INT0);
}

void int0_set_low_level(){
	EICRA &= ~((1 << ISC01) | (1 << ISC00));
	EICRA |= (0 << ISC01) | (0 << ISC00);
}

void int0_set_rising_falling_edge(){
	EICRA &= ~((1 << ISC01) | (1 << ISC00));
	EICRA |= (0 << ISC01) | (1 << ISC00);
}

void int0_set_falling_edge(){
	EICRA &= ~((1 << ISC01) | (1 << ISC00));
	EICRA |= (1 << ISC01) | (0 << ISC00);
}


void int0_set_rising_edge(){
	EICRA &= ~((1 << ISC01) | (1 << ISC00));
	EICRA |= (1 << ISC01) | (1 << ISC00);
}



/*******************************************************/
/*************************INT1**************************/

void int1_enable(){
	EIMSK |= (1 << INT1);
}

void int1_disable(){
	EIMSK &= ~(1 << INT1);
}

void int1_set_low_level(){
	EICRA &= ~((1 << ISC11) | (1 << ISC10));
	EICRA |= (0 << ISC11) | (0 << ISC10);
}

void int1_set_rising_falling_edge(){
	EICRA &= ~((1 << ISC11) | (1 << ISC10));
	EICRA |= (0 << ISC11) | (1 << ISC10);
}

void int1_set_falling_edge(){
	EICRA &= ~((1 << ISC11) | (1 << ISC10));
	EICRA |= (1 << ISC11) | (0 << ISC10);
}


void int1_set_rising_edge(){
	EICRA &= ~((1 << ISC11) | (1 << ISC10));
	EICRA |= (1 << ISC11) | (1 << ISC10);
}



/*******************************************************/
/*************************INT2**************************/



/*******************************************************/
/*************************PCINT**************************/

void pcint_enable(){
	PCICR |= (1 << PCIE0);
}

void pcint_disable(){
	PCICR &= ~(1 << PCIE0);
}

void pcint_pin_enable(uint8_t pin){
	PCMSK0 |= (1 << pin);
}

void pcint_pin_disable(uint8_t pin){
	PCMSK0 &= ~(1 << pin);
}

void pcint_pin_enable_all(){
	PCMSK0 = 0xFF;
}

void pcint_pin_disable_all(){
	PCMSK0 = 0x00;
}




#endif /* INTERRUPT_H_ */