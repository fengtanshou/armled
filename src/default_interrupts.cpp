//#include <algorithm>
#include <cstdint>
#include <cstring>

extern std::uint32_t _data;
extern std::uint32_t _edata;
extern std::uint32_t _data_load;

extern std::uint32_t _bss;
extern std::uint32_t _ebss;

int main();
extern "C" void __libc_init_array();
//void __init_array_start();

void __attribute__ ((interrupt)) reset_isr()
{
   // Copy .data to SRAM
//   std::memcpy(&_data, &_data_load, &_edata - &_data);
//   std::copy(_data, _edata, _data_load);
//   memcpy(&_data, &_data_load, &_edata - &_data);
   uint32_t *src = &_data_load;
   uint32_t *dst = &_data;
   while(dst != &_edata)
   {
      *dst++ = *src++;
   }

   // Zero .bss
//   std::memset(&_bss, 0, &_ebss - &_bss);
   uint32_t *bss_dst = &_bss;
   while(bss_dst != &_ebss)
   {
      *bss_dst++ = 0;
   }

   // Stack pointers?

   // Static constructors
   __libc_init_array();
//   __init_array_start();

   // Start
   // __extension__ allows non-pedantic code. In this case, getting the address of main.
   __extension__ main();

   // Exception if returning from start
}

void __attribute__ ((interrupt)) blocking_isr()
{
   while(true)
   {
   }
}
