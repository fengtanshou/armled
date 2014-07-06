#include <cstdint>

#define SYSCTL_BASE 0x400fe000

// This shifting works if working with 32-bit pointers
#define BIT1_MASK (1 << 1)
#define BIT1 1

#define PORTF 5
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


//PF1
//#define RED_LED_PIN 0x2

class A
{
public:
   A()
   {
//      (&PORTF_GPIODATA)[BIT1_MASK] = (1 << BIT1);
   }

   void b()
   {
      asm("nop");
   }
};

class Test
{
public:
   Test()
   {
      a.b();
   }

   static A a;
};

A Test::a;

Test t;

int main()
{
   // need to configure sysclk?
   // need to start bus?
   

   // Enable port clock in run mode
   RCGCGPIO |= (1 << PORTF);
   
   // Enable AHB (bus)
   GPIOHBCTL |= (1 << PORTF);

   // Need to wait 3 clocks before touching GPIO registers after switching bus
   for(int i = 0; i < 10; ++i)
   {
      asm("nop");
   }
   
   // Digital pin
   PORTF_GPIODEN |= 1 << BIT1;
   
   // Led pin output
   PORTF_GPIODIR |= 1 << BIT1;
   
   // Default 2mA drive

   t.a.b();
//   A &a_ = t.a;
   //.b();
//   Test test;
//   test.a.b();
   
   while(true)
   {
      (&PORTF_GPIODATA)[BIT1_MASK] = (1 << BIT1);
//      (&PORTF_GPIODATA)[BIT1_MASK] = (0 << BIT1);
   }

   return 0;
}
