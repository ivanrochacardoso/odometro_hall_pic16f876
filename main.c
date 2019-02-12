#include<16f876.h>
 
#use delay(clock=4000000)
#fuses XT,NOWDT,NOBROWNOUT,NOLVP

//biblioteca LCD
#include "flex_lcd.c"

//biblioteca auxiliar EEPROM
#include <ajudante.h> 
//----------------------------------------------------------------------

 #use rs232(baud=9600,PARITY=N, xmit=PIN_C6,rcv=PIN_C7)


#define	BOTAO1	PIN_A5	;//saida , pino 24
#define	BOTAO2	PIN_C5	;//
#define	LED     PIN_C0	;
#define	LED2     PIN_C4

//******************  *******************
long count;
long count2;
long medido;
float distancia;
float distancia_grv;

//---------------------------------------------------



void main(){
setup_adc_ports(NO_ANALOGS);
lcd_init();  // Always call this first. 
lcd_putc("\fMemória:"); 
delay_ms(10);

 
setup_timer_0(RTCC_EXT_L_TO_H | RTCC_DIV_1);
 set_timer0(0);
 
delay_ms(50);      //aguarda estabilizar oscilador 

float cird4;
count=0;
 
  cird4=23.2;//circunferencia/2 -> 2 imãs na roda
  
   medido=long_read_eeprom(0);
   distancia_grv=medido*cird4;
   printf(lcd_putc,"\n%fcm",distancia_grv);

delay_ms(3000);//exibe por 3 segundos memoria ultima medida  
   while(1){ 

      count=get_timer0();
      delay_ms(500); 

distancia=count*cird4;
distancia_grv=medido*cird4;
printf(lcd_putc,"\f%fcm",distancia);                               

      delay_ms(5);
      if(count>0){
	      long_write_eeprom(0,(long)count); 
      }else{
      printf(lcd_putc,"\n%fcm",distancia_grv);
      }
                                    
	delay_ms(5);
		
		 
   
} 

}

//=====================================================
