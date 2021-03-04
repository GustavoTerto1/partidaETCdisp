/*
 * File:   main.c
 * Author: 20185147
 * 
 * Created on 18 de Fevereiro de 2021, 15:09
 */


#include <xc.h>
#include "config.h"
#include "botoes.h"
#include "contatores.h"
#include "delay.h"
#include "disp7seg.h"


void main(void)
{
   unsigned char cont = 0;
    int t; 
    char estado = 0;
   
    while( 1 )
     {
        switch( estado )
         {
            case 0:
                    estado = 1;
                     break;
            case 1:
                    display7seg_init();
                    contatores_init();
                    botao_init();
                    estado = 2;
                     break;
                    
            case 2:        
                    if( s1() == 1 )
                        estado = 3;
                     break;    
            case 3:
                    
                    k1( 1 );
                    k2( 1 );
                    k3( 0 );
                    estado = 4;
                     break;
            case 4:         
                   t = 2000;
                    estado = 5;
                     break;
            case 5:
                    delay(1);
                    --t;
                    if( t <= 0)
                    estado = 6;
                    if ( s0() == 1 )
                    estado = 9; 
                     break;
            case 6:
                    k1 ( 1 );
                    k2 ( 0 );    
                    k3 ( 1 );  
                   
                    estado = 7;
                     break;
            case 7:
                   display7seg( cont );
                   ++cont;
                   if ( cont >= 10 )
                        cont = 0;     
                    estado = 8;
                    break; 
            case 8:
                    if( s0() == 1 )
                    estado = 9;
                    break;         
            case 9:
                    k1 ( 0 );
                    k2 ( 0 );    
                    k3 ( 0 );
                    estado = 2;
                    break;
                    
                         
                    
        }
          display7seg( cont );            
   }
}
