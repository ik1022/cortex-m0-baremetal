
#include "../A31G12x/reg_core/nvic.hpp"
#include "../A31G12x/reg_core/systick.hpp"

// #include "../A31G12x/A31G12x.h"

static volatile unsigned &pfmod   = *reinterpret_cast<unsigned *>(0x30000500UL);
static volatile unsigned &pfout   = *reinterpret_cast<unsigned *>(0x30000518UL);
static volatile unsigned &clkreg1 = *reinterpret_cast<unsigned *>(0x40001A00UL);
static volatile unsigned &clkreg2 = *reinterpret_cast<unsigned *>(0x40001820UL);

void main_app()
{
    clkreg1 = 0x5A690000 | (37 << 10) | (26 << 4);
    clkreg2 = 0x20;

    pfmod = 0x4000;

    io::SYSTICK.VAL.b.CURRENT = 0;
    io::SYSTICK.LOAD.b.RELOAD = 250000 - 1; // 2500=1ms
    io::SYSTICK.CSR.r         = 7;          // TICKINT , CLKSOURCE , ENABLE

    io::NVIC.isr_enable();

    while (1)
        ;
}

void SYSTICK_handler() { pfout ^= 0x80; }
