#ifndef INTERRUPT_H
#define INTERRUPT_H

#define ISR(vector_name) namespace interrupt { __attribute__ ((interrupt)) void vector_name(); } void interrupt::vector_name()

#endif
