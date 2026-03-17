/**
 * Handlers setup code for STM32F0xxxx MCUs.
 */

typedef void (*ptr_func_t)();

// Undefined handler is pointing to this function, this stop MCU.
// This function name must by not mangled, so must be C,
// because alias("..") is working only with C code
extern "C" void __stop_a31g12x()
{
    while (true)
        ;
}

// Handlers for Cortex-M core.
// These handler are with attribute 'weak' and can be overwritten
// by non-week function, default is __stop() function

__attribute__((weak, alias("__stop_a31g12x"))) void LVI_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void WUT_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void WDT_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void EINT0_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void EINT1_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void EINT2_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void EINT3_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER10_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER11_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER12_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void I2C0_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void USART10_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void WT_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER30_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void I2C1_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER20_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER21_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void USART11_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void ADC_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void UART0_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void UART1_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER13_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER14_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER15_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void TIMER16_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void I2C2_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void USART12_handler();
__attribute__((weak, alias("__stop_a31g12x"))) void USART13_handler();

// Dummy handler (for unused vectors)
extern void DUMMY_handler();

// Vector table for handlers
// This array will be placed in ".vectors" section defined in linker script.
__attribute__((section(".vectors_a31g12x"), used)) ptr_func_t __isr_vectors_a31g12x[] = {
  LVI_handler,     WUT_handler,     WDT_handler,     EINT0_handler,   EINT1_handler,   EINT2_handler,   EINT3_handler,
  TIMER10_handler, TIMER11_handler, TIMER12_handler, I2C0_handler,    USART10_handler, WT_handler,      TIMER30_handler,
  I2C1_handler,    TIMER20_handler, TIMER21_handler, USART11_handler, ADC_handler,     UART0_handler,   UART1_handler,
  TIMER13_handler, TIMER14_handler, TIMER15_handler, TIMER16_handler, I2C2_handler,    USART12_handler, USART13_handler,
};
