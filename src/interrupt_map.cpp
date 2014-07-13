#include <cstdint>

#include "interrupt.h"

// alias only works for symbols in the same translation unit
ISR(blocking_isr)
{
   while(true)
   {
   }
}

namespace interrupt
{

static const std::size_t ISR_VECTOR_LENGTH = 155;

extern "C" uint32_t _stack;

#define INTERRUPT_DEF __attribute__ ((weak, interrupt, alias("_ZN9interrupt12blocking_isrEv"))) void
INTERRUPT_DEF vector_reset();
INTERRUPT_DEF vector_non_maskable_interrupt();
INTERRUPT_DEF vector_hard_fault();
INTERRUPT_DEF vector_memory_management();
INTERRUPT_DEF vector_bus_fault();
INTERRUPT_DEF vector_usage_fault();
INTERRUPT_DEF vector_svcall();
INTERRUPT_DEF vector_debug_monitor();
INTERRUPT_DEF vector_pendsv();
INTERRUPT_DEF vector_systick();
INTERRUPT_DEF vector_gpio_port_a();
INTERRUPT_DEF vector_gpio_port_b();
INTERRUPT_DEF vector_gpio_port_c();
INTERRUPT_DEF vector_gpio_port_d();
INTERRUPT_DEF vector_gpio_port_e();
INTERRUPT_DEF vector_uart0();
INTERRUPT_DEF vector_uart1();
INTERRUPT_DEF vector_ssi0();
INTERRUPT_DEF vector_i2c0();
INTERRUPT_DEF vector_pwm0_fault();
INTERRUPT_DEF vector_pwm0_generator_0();
INTERRUPT_DEF vector_pwm0_generator_1();
INTERRUPT_DEF vector_pwm0_generator_2();
INTERRUPT_DEF vector_qei0();
INTERRUPT_DEF vector_adc0_sequence_0();
INTERRUPT_DEF vector_adc0_sequence_1();
INTERRUPT_DEF vector_adc0_sequence_2();
INTERRUPT_DEF vector_adc0_sequence_3();
INTERRUPT_DEF vector_watchdog_timers_0_and_1();
INTERRUPT_DEF vector_16_32_bit_timer_0a();
INTERRUPT_DEF vector_16_32_bit_timer_0b();
INTERRUPT_DEF vector_16_32_bit_timer_1a();
INTERRUPT_DEF vector_16_32_bit_timer_1b();
INTERRUPT_DEF vector_16_32_bit_timer_2a();
INTERRUPT_DEF vector_16_32_bit_timer_2b();
INTERRUPT_DEF vector_analog_comparator_0();
INTERRUPT_DEF vector_analog_comparator_1();
INTERRUPT_DEF vector_system_control();
INTERRUPT_DEF vector_flash_memory_control_and_eeprom46();
INTERRUPT_DEF vector_gpio_port_f();
INTERRUPT_DEF vector_uart2();
INTERRUPT_DEF vector_ssi1();
INTERRUPT_DEF vector_16_32_bit_timer_3a();
INTERRUPT_DEF vector_16_32_bit_timer_3b();
INTERRUPT_DEF vector_i2c1();
INTERRUPT_DEF vector_qei1();
INTERRUPT_DEF vector_can0();
INTERRUPT_DEF vector_can1();
INTERRUPT_DEF vector_hibernation_module();
INTERRUPT_DEF vector_usb();
INTERRUPT_DEF vector_pwm_generator_3();
INTERRUPT_DEF vector_udma_software();
INTERRUPT_DEF vector_udma_error();
INTERRUPT_DEF vector_adc1_sequence_0();
INTERRUPT_DEF vector_adc1_sequence_1();
INTERRUPT_DEF vector_adc1_sequence_2();
INTERRUPT_DEF vector_adc1_sequence_3();
INTERRUPT_DEF vector_ssi2();
INTERRUPT_DEF vector_ssi3();
INTERRUPT_DEF vector_uart3();
INTERRUPT_DEF vector_uart4();
INTERRUPT_DEF vector_uart5();
INTERRUPT_DEF vector_uart6();
INTERRUPT_DEF vector_uart7();
INTERRUPT_DEF vector_i2c2();
INTERRUPT_DEF vector_i2c3();
INTERRUPT_DEF vector_16_32_bit_timer_4a();
INTERRUPT_DEF vector_16_32_bit_timer_4b();
INTERRUPT_DEF vector_16_32_bit_timer_5a();
INTERRUPT_DEF vector_16_32_bit_timer_5b();
INTERRUPT_DEF vector_32_64_bit_timer_0a();
INTERRUPT_DEF vector_32_64_bit_timer_0b();
INTERRUPT_DEF vector_32_64_bit_timer_1a();
INTERRUPT_DEF vector_32_64_bit_timer_1b();
INTERRUPT_DEF vector_32_64_bit_timer_2a();
INTERRUPT_DEF vector_32_64_bit_timer_2b();
INTERRUPT_DEF vector_32_64_bit_timer_3a();
INTERRUPT_DEF vector_32_64_bit_timer_3b();
INTERRUPT_DEF vector_32_64_bit_timer_4a();
INTERRUPT_DEF vector_32_64_bit_timer_4b();
INTERRUPT_DEF vector_32_64_bit_timer_5a();
INTERRUPT_DEF vector_32_64_bit_timer_5b();
INTERRUPT_DEF vector_system_exception();
INTERRUPT_DEF vector_pwm1_generator_0();
INTERRUPT_DEF vector_pwm1_generator_1();
INTERRUPT_DEF vector_pwm1_generator_2();
INTERRUPT_DEF vector_pwm1_generator_3();
INTERRUPT_DEF vector_pwm1_fault();
INTERRUPT_DEF vector_reserved();

void (*const isr_vector[ISR_VECTOR_LENGTH])() __attribute__ ((section(".isr_vector"))) =
{
   //Make a struct instead? Want to show stack start is part of vector in documentation
   __extension__ reinterpret_cast<void (*)()>(&_stack),
   
   vector_reset,
   vector_non_maskable_interrupt,
   vector_hard_fault,
   vector_memory_management,
   vector_bus_fault,
   vector_usage_fault,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_svcall,
   vector_debug_monitor,
   vector_reserved,
   vector_pendsv,
   vector_systick,
   vector_gpio_port_a,
   vector_gpio_port_b,
   vector_gpio_port_c,
   vector_gpio_port_d,
   vector_gpio_port_e,
   vector_uart0,
   vector_uart1,
   vector_ssi0,
   vector_i2c0,
   vector_pwm0_fault,
   vector_pwm0_generator_0,
   vector_pwm0_generator_1,
   vector_pwm0_generator_2,
   vector_qei0,
   vector_adc0_sequence_0,
   vector_adc0_sequence_1,
   vector_adc0_sequence_2,
   vector_adc0_sequence_3,
   vector_watchdog_timers_0_and_1,
   vector_16_32_bit_timer_0a,
   vector_16_32_bit_timer_0b,
   vector_16_32_bit_timer_1a,
   vector_16_32_bit_timer_1b,
   vector_16_32_bit_timer_2a,
   vector_16_32_bit_timer_2b,
   vector_analog_comparator_0,
   vector_analog_comparator_1,
   vector_reserved,
   vector_system_control,
   vector_flash_memory_control_and_eeprom46,
   vector_gpio_port_f,
   vector_reserved,
   vector_reserved,
   vector_uart2,
   vector_ssi1,
   vector_16_32_bit_timer_3a,
   vector_16_32_bit_timer_3b,
   vector_i2c1,
   vector_qei1,
   vector_can0,
   vector_can1,
   vector_reserved,
   vector_reserved,
   vector_hibernation_module,
   vector_usb,
   vector_pwm_generator_3,
   vector_udma_software,
   vector_udma_error,
   vector_adc1_sequence_0,
   vector_adc1_sequence_1,
   vector_adc1_sequence_2,
   vector_adc1_sequence_3,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_ssi2,
   vector_ssi3,
   vector_uart3,
   vector_uart4,
   vector_uart5,
   vector_uart6,
   vector_uart7,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_i2c2,
   vector_i2c3,
   vector_16_32_bit_timer_4a,
   vector_16_32_bit_timer_4b,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_16_32_bit_timer_5a,
   vector_16_32_bit_timer_5b,
   vector_32_64_bit_timer_0a,
   vector_32_64_bit_timer_0b,
   vector_32_64_bit_timer_1a,
   vector_32_64_bit_timer_1b,
   vector_32_64_bit_timer_2a,
   vector_32_64_bit_timer_2b,
   vector_32_64_bit_timer_3a,
   vector_32_64_bit_timer_3b,
   vector_32_64_bit_timer_4a,
   vector_32_64_bit_timer_4b,
   vector_32_64_bit_timer_5a,
   vector_32_64_bit_timer_5b,
   vector_system_exception,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_reserved,
   vector_pwm1_generator_0,
   vector_pwm1_generator_1,
   vector_pwm1_generator_2,
   vector_pwm1_generator_3,
   vector_pwm1_fault,
};

}
