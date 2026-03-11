// // define used registers
// static volatile unsigned &RCC_AHB1 = *reinterpret_cast<unsigned *>(0x40021014);
// static volatile unsigned &GPIOA_MODER = *reinterpret_cast<unsigned *>(0x48000000);
// static volatile unsigned &GPIOA_BSRR = *reinterpret_cast<unsigned *>(0x48000018);

// // #include <cmath>

// // application
// void main_app() {
//     RCC_AHB1 |= 0x00020000;  // enable clock for GPIOA
//     GPIOA_MODER |= 0x40000000;  // set output on GPIOA.P15
//     // double x = 0.0;
//     // double y = 0.0;
//     while (true) {
//         // y = sin(x);
//         // x += y;
//         GPIOA_BSRR = 0x00008000;  // set output on GPIOA.P15
//         GPIOA_BSRR = 0x80000000;  // clear output on GPIOA.P15
//     }
// }


// int *pfmod = (int *)0x30000500UL;
// int *pfout = (int *)0x30000518UL;

static volatile unsigned &pfmod   = *reinterpret_cast<unsigned *>(0x30000500UL);
static volatile unsigned &pfout   = *reinterpret_cast<unsigned *>(0x30000518UL);
static volatile unsigned &clkreg1 = *reinterpret_cast<unsigned *>(0x40001A00UL);
static volatile unsigned &clkreg2 = *reinterpret_cast<unsigned *>(0x40001820UL);

void main_app()
{
    volatile int i = 0;
    volatile int j = 0;

    //*((int *)0x40001A00) = 0x5A690000 | (37 << 10) | (26 << 4);
    //*((int *)0x40001820) = 0x20;
    clkreg1 = 0x5A690000 | (37 << 10) | (26 << 4);
    clkreg2 = 0x20;

    pfmod = 0x4000;

    for (j = 0; j < 20; j++)
    {
        while (1)
        {
            if (++i >= 0x1fff)
            {
                i      = 0;
                pfout ^= 0x80;
                break;
            }
        }
    }


    i = 0;
    while (1)
    {
        i++;
        if (i >= 0xffff)
        {
            i      = 0;
            pfout ^= 0x80;
        }
    }
}
