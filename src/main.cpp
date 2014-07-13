#include <cstdint>

#include "interrupt.h"

#define SYSCTL_BASE 0x400fe000

// This shifting works if working with 32-bit pointers
#define BIT1_MASK (1 << 1)
#define BIT1 1

#define PORTF 5
#define R5 5
#define GPIOHBCTL (*((volatile std::uint32_t *)(SYSCTL_BASE + 0x6c)))
#define RCGCGPIO (*((volatile std::uint32_t *)(SYSCTL_BASE + 0x608)))

#define PORTF_AHB_BASE 0x4005d000
#define PORTF_GPIODATA (*((volatile std::uint32_t *)(PORTF_AHB_BASE)))
#define PORTF_GPIODIR (*((volatile std::uint32_t *)(PORTF_AHB_BASE + 0x400)))
#define PORTF_GPIODEN (*((volatile std::uint32_t *)(PORTF_AHB_BASE + 0x51c)))


// #define PORTF_APB_BASE 0x40025000
// #define PORTF_GPIODATA (*((std::uint32_t *)(PORTF_APB_BASE)))
// #define PORTF_GPIODIR (*((std::uint32_t *)(PORTF_APB_BASE + 0x400)))
// #define PORTF_GPIODEN (*((std::uint32_t *)(PORTF_APB_BASE + 0x51c)))

#define RCGCTIMER (*((volatile std::uint32_t *)(SYSCTL_BASE + 0x604)))
#define R0 0

#define TIMER0_16_32_BASE 0x40030000
#define TIMER0_16_32_GPTMTAMR (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x004)))
#define TIMER0_16_32_GPTMCTL (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x00c)))
#define TIMER0_16_32_GPTMIMR (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x018)))
#define TIMER0_16_32_GPTMTAV (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x050)))
#define TIMER0_16_32_GPTMRIS (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x01c)))
#define TIMER0_16_32_GPTMMIS (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x020)))
#define TIMER0_16_32_GPTMICR (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x024)))
#define TIMER0_16_32_GPTMTAILR (*((volatile std::uint32_t *)(TIMER0_16_32_BASE + 0x028)))

#define TAMR 0
#define TAEN 0
#define TATOIM 0
#define TATOCINT 0


#define TIMER0A_16_32_INT_NUM 19
#define CORE_PERIPH_BASE 0xe000e000
// Treat EN* as 128 bit variable? Bit order?
#define EN0 (*((volatile std::uint32_t *)(CORE_PERIPH_BASE + 0x100)))

int main()
{
   // need to configure sysclk?
   // need to start bus?
   

   // Enable port clock in run mode
   RCGCGPIO |= (1 << R5);
   
   // Enable AHB (bus)
   GPIOHBCTL |= (1 << PORTF);

   // Enable timer module clock in run mode
   RCGCTIMER |= (1 << R0);

   // Need to wait 3 clocks before touching GPIO registers after switching bus
   // Need to wait 3 clocks before touching timer registers after switching bus
   for(int i = 0; i < 10; ++i)
   {
      asm("nop");
   }
   
   // Digital pin
   PORTF_GPIODEN |= 1 << BIT1;
   
   // Led pin output
   PORTF_GPIODIR |= 1 << BIT1;
   
   // Default 2mA drive

//   t.a.b();
//   A &a_ = t.a;
   //.b();
//   Test test;
//   test.a.b();


   EN0 = (1 << TIMER0A_16_32_INT_NUM);

   //GPTMCL TnEN = 0;
   //GPTMCFG = 0x0;
   TIMER0_16_32_GPTMTAMR |= (0x2 << TAMR);
   TIMER0_16_32_GPTMTAILR = 80000000;
   TIMER0_16_32_GPTMIMR |= (1 << TATOIM);
   TIMER0_16_32_GPTMCTL |= (1 << TAEN);
   
   
   while(true)
   {
//      (&PORTF_GPIODATA)[BIT1_MASK] = (1 << BIT1);
//      (&PORTF_GPIODATA)[BIT1_MASK] = (0 << BIT1);
      int a = TIMER0_16_32_GPTMTAV;
      int ris = TIMER0_16_32_GPTMRIS;
      int mis = TIMER0_16_32_GPTMMIS;
      asm("nop");
   }

   return 0;
}

ISR(vector_16_32_bit_timer_0a)
{
   // Clear interrupt flag early so interrupt won't be retriggered by NVIC
   TIMER0_16_32_GPTMICR = (1 << TATOCINT);

   (&PORTF_GPIODATA)[BIT1_MASK] = ~(&PORTF_GPIODATA)[BIT1_MASK];
}
