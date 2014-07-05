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
