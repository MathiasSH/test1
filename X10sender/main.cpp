/*
 * X10sender.cpp
 *
 * Created: 11-05-2022 13:34:11
 * Author : malle
 */ 

#include <avr/io.h>
#include "X10sender.h"
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>


#define STARTBIT 0b1110
#define STOPBIT 0b000000

volatile unsigned int oldUseCase = 0b010101;
volatile unsigned int newUseCase = 0b010101;
volatile unsigned int antal_bits = 0;
volatile unsigned int casesSend = 0;
volatile unsigned int testUseCase = 0b011001;
volatile unsigned int send = 0;

void initExtInts();

X10sender X10s;

int main(void)
{
	initExtInts();
	sei();	
	// if (new code != old code)
	// tænd EIMSK |= 0b00000100;
	
	_delay_ms(10000);
	send = 1;
	
    while (1) 
    {
		if (oldUseCase != newUseCase)
		{
			//EIMSK |= 0b00000010;   //sætter INT1 til any edge interrupt. dette er dumt at tænde midt i det hele. da det er en "edge" når det bliver tændt.
		}
    }
}

ISR (INT1_vect)
{
	if(!send)
	{
		return;
	}
	if (casesSend < 2)
	{
		if (antal_bits < 4)
		{
			X10s.sendBit(STARTBIT & (1<<(3 - antal_bits)));
			antal_bits++;
			return;
		}	
		else if (antal_bits < 10)
		{
			X10s.sendBit(testUseCase & (1<<(9 - antal_bits)));
			antal_bits++;
			return;
		}
		else
		{
			X10s.sendBit(0);
			antal_bits++;
		}		
	}
	if(!(antal_bits == 16))
	{
		return;
	}
	else
	{
		casesSend++;
		antal_bits = 0;
	}
		
	if (casesSend == 2)
	{
		send = 0;
		return;
	}
	return;
	
}

void initExtInts()
{
	// ZERO-CROSS detekter, interrupt ved edge-skift. Ben44, PD1 INT1.
	EICRA = 0b00000100;
	// Enable extern interrupts INT1.
	EIMSK |= 0b00000010;
}

