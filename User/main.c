#include "ALL_Includes.h"//包含所需的头文件

int main(void)
{	
	unsigned	int HIGH_CH1_112M[44] = 
{
0x00221E  ,
0x4001AF ,
0x3E0000 ,
0x3D0001 ,
0x3B0000 ,
0x3003FC ,
0x2F08D4 ,
0x2E14A2 ,
0x2DF3B6 ,
0x2C3AFD ,
0x2B0000 ,
0x2A0000 ,
0x29FFFF ,
0x28FFFF ,
0x278204 ,
0x260024 ,
0x255000 ,
0x240811 ,
0x23021B ,
0x22C3F0 ,
0x214210 ,
0x204210 ,
0x1F0401 ,
0x1E0035 ,
0x1D0084 ,
0x1C2924 ,
0x190000 ,
0x180509 ,
0x178842 ,
0x162300 ,
0x14012C ,
0x130965 ,
0x0E0FFE ,
0x0D4000 ,
0x0C7001 ,
0x0B0028 ,
0x0A12D8 ,
0x090302 ,
0x081084 ,
0x0728B2 ,
0x041943 ,
0x020500 ,
0x010808 ,
0x00221C
	
	};	

	
	Delay_Init(48);
	//LED_Init();
	USART1_Init();
	T_Adc_Init();
	//Init_ADF5355();	
	Init_LMX259x();
	WriteToLMX259x( 44, HIGH_CH1_112M);
	while (1)
	{
		delay_ms(100);
		Get_Temprate();	
	}
	
}

int fputc(int ch, FILE *f)

{

USART_SendData(USART1, (unsigned char) ch);// USART1 ???? USART2 ?

while (!(USART1->ISR & USART_FLAG_TXE));

return (ch);

}



int GetKey (void) {

while (!(USART1->ISR & USART_FLAG_RXNE));

return ((int)(USART1->TDR & 0x1FF));

}
	

