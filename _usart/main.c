/*----------------------------------------------------------------------------
/
/
/----------------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_usart.h"
/*---------------------------------------------------------------------------*/
#include "xprintf.h"
#include "usart1.h"
#include "digital.h"
#include "systick_delay.h"
/*---------------------------------------------------------------------------*/
static void hardware_init();
/*---------------------------------------------------------------------------*/
int main(void)
{  
  uint32_t cnt = 0;

  hardware_init();

  while(1)
  {
    xprintf("> Counter: %d\r\n",cnt++);    
    _delay_nop(100);   
  }

  return 0;
}
/*---------------------------------------------------------------------------*/
static void hardware_init()
{
  /* init systick and delay system */
  systick_init(SYSTICK_1MS);  

  /* init uart and enable xprintf library */
  usart1_init(115200);
  xdev_out(usart1_sendChar);

  /* small delay for general stabilisation */
  _delay_ms(10);
}
/*---------------------------------------------------------------------------*/
