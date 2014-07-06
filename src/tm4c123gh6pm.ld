/*ENTRY(_start)*/

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

/* exidx = Exception Index (table?) */

SECTIONS
{
	_stack = ORIGIN(SRAM) + LENGTH(SRAM);

	.text :
	{
		KEEP(*(.isr_vector))
		*(.text*)
	} >FLASH

/*
	. = ALIGN(4);
*/

	.init :
	{
		KEEP(*(.init))
	} >FLASH

	.fini :
	{
		KEEP(*(.fini))
	} >FLASH

/*
	.preinit_array :
	{
		PROVIDE_HIDDEN(__preinit_array_start = .);
		KEEP(*(.preinit_array*))
		PROVIDE_HIDDEN(__preinit_array_end = .);
	} >FLASH
*/

	.init_array :
	{
		PROVIDE_HIDDEN(__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array*))
		PROVIDE_HIDDEN(__init_array_end = .);
	} >FLASH

	.fini_array :
	{
		PROVIDE_HIDDEN(__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array*))
		PROVIDE_HIDDEN(__fini_array_end = .);
	} >FLASH

	.ctors :
	{
		KEEP(*crtbegin.o(.ctors))
		KEEP(*(EXCLUDE_FILE (*crtend.o) .ctors))
		KEEP(*(SORT(.ctors.*)))
		KEEP(*crtend.o(.ctors))
	} >FLASH

	.dtors :
	{
		KEEP(*crtbegin.o(.dtors))
		KEEP(*(EXCLUDE_FILE (*crtend.o) .dtors))
		KEEP(*(SORT(.dtors.*)))
		KEEP(*crtend.o(.dtors))
	} >FLASH


	/* Exception tables, sorted for fast search (?) */
	/* Maybe see: Exception Handling ABI for the ARM Architecture */
	.ARM.exidx :
	{
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
 	} >FLASH

	.rodata :
	{
		*(.rodata*)
	} >FLASH

	.data :
	{
		_data_load = LOADADDR(.data);
		_data = .;
		*(.data*)
		_edata = .;
	} >SRAM AT>FLASH

	.bss :
	{
		_bss = .;
		__bss_start__ = .;
		*(.bss*)
		_ebss = .;
		__bss_end__ = .;
	} >SRAM

	PROVIDE(__end__ = _ebss);
	PROVIDE(end = _ebss);
}
