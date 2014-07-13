//#include <algorithm>
#include <cstdint>
#include <cstring>

#include "interrupt.h"

// memcpy and memset count calculation is dependent on the type
extern std::uint8_t _data;
extern std::uint8_t _edata;
extern std::uint8_t _data_load;

extern std::uint8_t _bss;
extern std::uint8_t _ebss;

int main();
extern "C" void __libc_init_array();
//void __init_array_start();

ISR(vector_reset)
{
   // Copy .data to SRAM
   std::memcpy(&_data, &_data_load, &_edata - &_data);

   // Zero .bss
   std::memset(&_bss, 0, &_ebss - &_bss);

   // Stack pointers?

   // Static constructors
   __libc_init_array();
//   __init_array_start();

   // Start
   // __extension__ allows non-pedantic code. In this case, getting the address of main.
   __extension__ main();

   // Exception if returning from start
}
