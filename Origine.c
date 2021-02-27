/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 3
Descrizione: Dato un array di bit, restituire le posizioni dei soli bit
uguali a 1.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input									//0xAA,0xFC,0x09
	unsigned char vet[] = {0x3E,0x12,0x25,0x7F,0xC0,0xA7,0x3D,0xEC,0x02 };	//Array di byte
												//(da considerare come una sequenza di bit)
	unsigned short int len = 67 ; //19			//Lunghezza (numero di bit)
	
								 //vet={0x3E,0x12,0x25,0x7F,0xC0,0xA7,0x3D,0xEC,0x02} 
												// Output
	short posizioni[1024]; //Posizioni dei soli bit con valore 1

	__asm
	{
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI,ESI

		MOV DX,len

		
		Pre:          
					  MOV ESI,8
					  MOV AH,vet[ECX]
					  JMP Ciclo

	    Ciclo:				CMP ESI,0		//TEST AH, AH
							JE Fine1		//JZ Fine1
	                        SHR AH, 1
					        JC Salto
							INC EBX
						    CMP EBX,EDX //19
							JA Fine
						    DEC ESI
							JMP Ciclo
							

		Salto:				
							MOV posizioni[EDI*2],BX
							INC EDI
							INC EBX
							DEC ESI
							JMP Ciclo
	
			Fine1 :
							INC ECX
							JMP Pre
			Fine :
		MOV posizioni[EDI*2], -1

			




	}
			// Stampa su video

			int i = 0;
		while (i <= len && posizioni[i] != -1)
		{
			printf("%d\n", posizioni[i++]);
		}
		system("pause");
	}

