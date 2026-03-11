MEMORY {
    FLASH(rx) : ORIGIN = 0x00000000, LENGTH = 32K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 4K
}

INCLUDE "ld/_flash.ld"
INCLUDE "ld/_sram.ld"
