/**
 * @{
 *
 * @file
 * @brief       nrf51 register mapping riot 
 *
 * @}
 */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

#include "nrf51.h"
#include "vtimer.h"

#define PRINTHEAD(X) printf("\n\n%s%s%s\n\n", "==> ", #X, " ")
#define PRINTH(X,Y) printf("%-36s: 0x%08lx\n", #X"."#Y, X->Y)
#define PRINTB(W,X,Y,Z) printf("%-36s: %ld\n", #W"."#X"."#Y, ((W->X) >> (Z) & 1))
#define PRINT(X) printf("%-36s: 0x%08lx\n", #X, X)

int main(void)
{
    // wait a bit
    vtimer_usleep(1000 * 1000);

    printf("Board: %s (%s)\n", RIOT_BOARD, RIOT_MCU);
    printf("Starting nrf51 register mapping riot!\n");

    PRINTHEAD("Peripherial memory map");
    PRINT(NRF_POWER_BASE);
    PRINT(NRF_CLOCK_BASE);
    PRINT(NRF_MPU_BASE);
    PRINT(NRF_PU_BASE);
    PRINT(NRF_AMLI_BASE);
    PRINT(NRF_RADIO_BASE);
    PRINT(NRF_UART0_BASE);
    PRINT(NRF_SPI0_BASE);
    PRINT(NRF_TWI0_BASE);
    PRINT(NRF_SPI1_BASE);
    PRINT(NRF_TWI1_BASE);
    PRINT(NRF_SPIS1_BASE);
    PRINT(NRF_GPIOTE_BASE);
    PRINT(NRF_ADC_BASE);
    PRINT(NRF_TIMER0_BASE);
    PRINT(NRF_TIMER1_BASE);
    PRINT(NRF_TIMER2_BASE);
    PRINT(NRF_RTC0_BASE);
    PRINT(NRF_TEMP_BASE);
    PRINT(NRF_RNG_BASE);
    PRINT(NRF_ECB_BASE);
    PRINT(NRF_AAR_BASE);
    PRINT(NRF_CCM_BASE);
    PRINT(NRF_WDT_BASE);
    PRINT(NRF_RTC1_BASE);
    PRINT(NRF_QDEC_BASE);
    PRINT(NRF_LPCOMP_BASE);
    PRINT(NRF_SWI_BASE);
    PRINT(NRF_NVMC_BASE);
    PRINT(NRF_PPI_BASE);
    PRINT(NRF_FICR_BASE);
    PRINT(NRF_UICR_BASE);
    PRINT(NRF_GPIO_BASE);

    PRINTHEAD("NRF_POWER - Power control");
    PRINTB(NRF_POWER, INTENSET, POFWARN, 2);
    PRINTB(NRF_POWER, INTENCLR, POFWARN, 2);
    PRINTB(NRF_POWER, RESETREAS, RESTPIN, 0);
    PRINTB(NRF_POWER, RESETREAS, DOG, 1);
    PRINTB(NRF_POWER, RESETREAS, SREQ, 2);
    PRINTB(NRF_POWER, RESETREAS, LOCKUP, 3);
    PRINTB(NRF_POWER, RESETREAS, OFF, 16);
    PRINTB(NRF_POWER, RESETREAS, LPCOMP, 17);
    PRINTB(NRF_POWER, RESETREAS, DIF, 18);
    PRINTB(NRF_POWER, RAMSTATUS, RAMBLOCK0, 0);
    PRINTB(NRF_POWER, RAMSTATUS, RAMBLOCK1, 1);
    PRINTB(NRF_POWER, RAMSTATUS, RAMBLOCK2, 2);
    PRINTB(NRF_POWER, RAMSTATUS, RAMBLOCK3, 3);
    PRINTB(NRF_POWER, POFCON, POF, 0);
    PRINTB(NRF_POWER, POFCON, TRESHOLD, 1);
    PRINTB(NRF_POWER, POFCON, TRESHHOLD, 2);
    PRINTH(NRF_POWER, GPREGRET);
    PRINTB(NRF_POWER, RAMON, ONRAM0, 0);
    PRINTB(NRF_POWER, RAMON, ONRAM1, 1);
    PRINTB(NRF_POWER, RAMON, OFFRAM0, 16);
    PRINTB(NRF_POWER, RAMON, OFFRAM1, 17);
    PRINTB(NRF_POWER, RESET, RESET, 0);
    PRINTB(NRF_POWER, RAMONB, ONRAM2, 0);
    PRINTB(NRF_POWER, RAMONB, ONRAM3, 1);
    PRINTB(NRF_POWER, RAMONB, OFFRAM2, 16);
    PRINTB(NRF_POWER, RAMONB, OFFRAM3, 17);
    PRINTB(NRF_POWER, DCDCEN, DCDCEN, 0);

    PRINTHEAD("NRF_CLOCK - Clock control");
    PRINTB(NRF_CLOCK, INTENSET, HFCLKSTARTED, 0);
    PRINTB(NRF_CLOCK, INTENSET, LFCLKSTARTED, 1);
    PRINTB(NRF_CLOCK, INTENSET, DONE, 3);
    PRINTB(NRF_CLOCK, INTENSET, CTTO, 4);
    PRINTB(NRF_CLOCK, INTENCLR, HFCLKSTARTED, 0);
    PRINTB(NRF_CLOCK, INTENCLR, LFCLKSTARTED, 1);
    PRINTB(NRF_CLOCK, INTENCLR, DONE, 3);
    PRINTB(NRF_CLOCK, INTENCLR, CTTO, 4);
    PRINTB(NRF_CLOCK, HFCLKRUN, STATUS, 0);
    PRINTB(NRF_CLOCK, HFCLKSTAT, SRC, 0);
    PRINTB(NRF_CLOCK, HFCLKSTAT, STATE, 16);
    PRINTB(NRF_CLOCK, LFCLKRUN, STATUS, 0);
    PRINTB(NRF_CLOCK, LFCLKSTAT, SRC, 0);
    PRINTB(NRF_CLOCK, LFCLKSTAT, SRC, 1);
    PRINTB(NRF_CLOCK, LFCLKSTAT, STATE, 16);
    PRINTB(NRF_CLOCK, LFCLKSRCCOPY, SRC, 0);
    PRINTB(NRF_CLOCK, LFCLKSRCCOPY, SRC, 1);
    PRINTB(NRF_CLOCK, LFCLKSRC, SRC, 0);
    PRINTB(NRF_CLOCK, LFCLKSRC, SRC, 1);
    PRINTH(NRF_CLOCK, CTIV);
    PRINTH(NRF_CLOCK, XTALFREQ);

    PRINTHEAD("NRF_TIMER - Timer 0");
    PRINTB(NRF_TIMER0, SHORTS, COMPARE0_CLEAR, 0);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE1_CLEAR, 1);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE2_CLEAR, 2);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE3_CLEAR, 3);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE0_STOP, 8);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE1_STOP, 9);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE2_STOP, 10);
    PRINTB(NRF_TIMER0, SHORTS, COMPARE3_STOP, 11);
    PRINTB(NRF_TIMER0, INTENSET, COMPARE0, 16);
    PRINTB(NRF_TIMER0, INTENSET, COMPARE1, 17);
    PRINTB(NRF_TIMER0, INTENSET, COMPARE2, 18);
    PRINTB(NRF_TIMER0, INTENSET, COMPARE3, 19);
    PRINTB(NRF_TIMER0, INTENCLR, COMPARE0, 16);
    PRINTB(NRF_TIMER0, INTENCLR, COMPARE1, 17);
    PRINTB(NRF_TIMER0, INTENCLR, COMPARE2, 18);
    PRINTB(NRF_TIMER0, INTENCLR, COMPARE3, 19);
    PRINTB(NRF_TIMER0, MODE, MODE, 0);
    PRINTB(NRF_TIMER0, BITMODE, BITMODE, 0);
    PRINTB(NRF_TIMER0, BITMODE, BITMODE, 1);
    PRINTH(NRF_TIMER0, PRESCALER);
    //PRINTH(NRF_TIMER0, CC);

    PRINTHEAD("NRF_RTC - Real time counter 0");
    PRINTB(NRF_RTC0, INTENSET, TICK, 0);
    PRINTB(NRF_RTC0, INTENSET, OVRFLW, 1);
    PRINTB(NRF_RTC0, INTENSET, COMPARE0, 16);
    PRINTB(NRF_RTC0, INTENSET, COMPARE1, 17);
    PRINTB(NRF_RTC0, INTENSET, COMPARE2, 18);
    PRINTB(NRF_RTC0, INTENSET, COMPARE3, 19);
    PRINTB(NRF_RTC0, INTENCLR, TICK, 0);
    PRINTB(NRF_RTC0, INTENCLR, OVRFLW, 1);
    PRINTB(NRF_RTC0, INTENCLR, COMPARE0, 16);
    PRINTB(NRF_RTC0, INTENCLR, COMPARE1, 17);
    PRINTB(NRF_RTC0, INTENCLR, COMPARE2, 18);
    PRINTB(NRF_RTC0, INTENCLR, COMPARE3, 19);
    PRINTB(NRF_RTC0, EVTEN, TICK, 0);
    PRINTB(NRF_RTC0, EVTEN, OVRFLW, 1);
    PRINTB(NRF_RTC0, EVTEN, COMPARE0, 16);
    PRINTB(NRF_RTC0, EVTEN, COMPARE1, 17);
    PRINTB(NRF_RTC0, EVTEN, COMPARE2, 18);
    PRINTB(NRF_RTC0, EVTEN, COMPARE3, 19);
    PRINTB(NRF_RTC0, EVTENSET, TICK, 0);
    PRINTB(NRF_RTC0, EVTENSET, OVRFLW, 1);
    PRINTB(NRF_RTC0, EVTENSET, COMPARE0, 16);
    PRINTB(NRF_RTC0, EVTENSET, COMPARE1, 17);
    PRINTB(NRF_RTC0, EVTENSET, COMPARE2, 18);
    PRINTB(NRF_RTC0, EVTENSET, COMPARE3, 19);
    PRINTB(NRF_RTC0, EVTENCLR, TICK, 0);
    PRINTB(NRF_RTC0, EVTENCLR, OVRFLW, 1);
    PRINTB(NRF_RTC0, EVTENCLR, COMPARE0, 16);
    PRINTB(NRF_RTC0, EVTENCLR, COMPARE1, 17);
    PRINTB(NRF_RTC0, EVTENCLR, COMPARE2, 18);
    PRINTB(NRF_RTC0, EVTENCLR, COMPARE3, 19);
    PRINTH(NRF_RTC0, COUNTER);
    PRINTH(NRF_RTC0, PRESCALER);
    //PRINTH(NRF_RTC0, CC);

    PRINTHEAD("NRF_RTC - Real time counter 1");
    PRINTB(NRF_RTC1, INTENSET, TICK, 0);
    PRINTB(NRF_RTC1, INTENSET, OVRFLW, 1);
    PRINTB(NRF_RTC1, INTENSET, COMPARE0, 16);
    PRINTB(NRF_RTC1, INTENSET, COMPARE1, 17);
    PRINTB(NRF_RTC1, INTENSET, COMPARE2, 18);
    PRINTB(NRF_RTC1, INTENSET, COMPARE3, 19);
    PRINTB(NRF_RTC1, INTENCLR, TICK, 0);
    PRINTB(NRF_RTC1, INTENCLR, OVRFLW, 1);
    PRINTB(NRF_RTC1, INTENCLR, COMPARE0, 16);
    PRINTB(NRF_RTC1, INTENCLR, COMPARE1, 17);
    PRINTB(NRF_RTC1, INTENCLR, COMPARE2, 18);
    PRINTB(NRF_RTC1, INTENCLR, COMPARE3, 19);
    PRINTB(NRF_RTC1, EVTEN, TICK, 0);
    PRINTB(NRF_RTC1, EVTEN, OVRFLW, 1);
    PRINTB(NRF_RTC1, EVTEN, COMPARE0, 16);
    PRINTB(NRF_RTC1, EVTEN, COMPARE1, 17);
    PRINTB(NRF_RTC1, EVTEN, COMPARE2, 18);
    PRINTB(NRF_RTC1, EVTEN, COMPARE3, 19);
    PRINTB(NRF_RTC1, EVTENSET, TICK, 0);
    PRINTB(NRF_RTC1, EVTENSET, OVRFLW, 1);
    PRINTB(NRF_RTC1, EVTENSET, COMPARE0, 16);
    PRINTB(NRF_RTC1, EVTENSET, COMPARE1, 17);
    PRINTB(NRF_RTC1, EVTENSET, COMPARE2, 18);
    PRINTB(NRF_RTC1, EVTENSET, COMPARE3, 19);
    PRINTB(NRF_RTC1, EVTENCLR, TICK, 0);
    PRINTB(NRF_RTC1, EVTENCLR, OVRFLW, 1);
    PRINTB(NRF_RTC1, EVTENCLR, COMPARE0, 16);
    PRINTB(NRF_RTC1, EVTENCLR, COMPARE1, 17);
    PRINTB(NRF_RTC1, EVTENCLR, COMPARE2, 18);
    PRINTB(NRF_RTC1, EVTENCLR, COMPARE3, 19);
    PRINTH(NRF_RTC1, COUNTER);
    PRINTH(NRF_RTC1, PRESCALER);
    //PRINTH(NRF_RTC1, CC);

    PRINTHEAD("NRF_WDT - Watchdog timer");
    PRINTB(NRF_WDT, INTENSET, TINEOUT, 0);
    PRINTB(NRF_WDT, INTENCLR, TIMEOUT, 0);
    PRINTB(NRF_WDT, RUNSTATUS, RUNSTATUS, 0);
    PRINTB(NRF_WDT, REQSTATUS, RR0, 0);
    PRINTB(NRF_WDT, REQSTATUS, RR1, 1);
    PRINTB(NRF_WDT, REQSTATUS, RR2, 2);
    PRINTB(NRF_WDT, REQSTATUS, RR3, 3);
    PRINTB(NRF_WDT, REQSTATUS, RR4, 4);
    PRINTB(NRF_WDT, REQSTATUS, RR5, 5);
    PRINTB(NRF_WDT, REQSTATUS, RR6, 6);
    PRINTB(NRF_WDT, REQSTATUS, RR7, 7);
    PRINTH(NRF_WDT, CRV);
    PRINTB(NRF_WDT, RREN, RR0, 0);
    PRINTB(NRF_WDT, RREN, RR1, 1);
    PRINTB(NRF_WDT, RREN, RR2, 2);
    PRINTB(NRF_WDT, RREN, RR3, 3);
    PRINTB(NRF_WDT, RREN, RR4, 4);
    PRINTB(NRF_WDT, RREN, RR5, 5);
    PRINTB(NRF_WDT, RREN, RR6, 6);
    PRINTB(NRF_WDT, RREN, RR7, 7);
    PRINTB(NRF_WDT, CONFIG, SLEEP, 1);
    PRINTB(NRF_WDT, CONFIG, HALT, 3);
    //PRINTH(NRF_WDT, RR);

    PRINTHEAD("NRF_RNG - Random number generator");
    PRINTB(NRF_RNG, SHORTS, VALRDY_STOP, 0);
    PRINTB(NRF_RNG, INTENSET, VALRDY, 0);
    PRINTB(NRF_RNG, INTENCLR, VALRDY, 0);
    PRINTB(NRF_RNG, CONFIG, DERCEN, 0);
    PRINTH(NRF_RNG, VALUE);

    PRINTHEAD("NRF_TEMP - Temperature sensor");
    PRINTB(NRF_TEMP, INTENSET, DATARDY, 0);
    PRINTB(NRF_TEMP, INTENCLR, DATARDY, 0);
    PRINTH(NRF_TEMP, TEMP);
    
    PRINTHEAD("NRF_AAR - Accelerated address resolver");
    PRINTB(NRF_AAR, INTENSET, END, 0);
    PRINTB(NRF_AAR, INTENSET, RESOLVED, 1);
    PRINTB(NRF_AAR, INTENSET, NOTRESOLVED, 2);
    PRINTB(NRF_AAR, INTENCLR, END, 0);
    PRINTB(NRF_AAR, INTENCLR, RESOLVED, 1);
    PRINTB(NRF_AAR, INTENCLR, NOTRESOLVED, 2);
    PRINTH(NRF_AAR, STATUS);
    PRINTB(NRF_AAR, ENABLE, ENABLE, 0);
    PRINTB(NRF_AAR, ENABLE, ENABLE, 1);
    PRINTH(NRF_AAR, NIRK);
    PRINTH(NRF_AAR, IRKPTR);
    PRINTH(NRF_AAR, ADDRPTR);
    PRINTH(NRF_AAR, SCRATCHPTR);

    PRINTHEAD("NRF_ADC - Analog to digital converter");
    PRINTB(NRF_ADC, INTENSET, END, 0);
    PRINTB(NRF_ADC, INTENCLR, END, 0);
    PRINTB(NRF_ADC, BUSY, BUSY, 0);
    PRINTB(NRF_ADC, ENABLE, ENABLE, 0);
    PRINTB(NRF_ADC, ENABLE, ENABLE, 1);
    PRINTB(NRF_ADC, CONFIG, RES, 0);
    PRINTB(NRF_ADC, CONFIG, RES, 1);
    PRINTB(NRF_ADC, CONFIG, INPSEL, 2);
    PRINTB(NRF_ADC, CONFIG, INPSEL, 3);
    PRINTB(NRF_ADC, CONFIG, INPSEL, 4);
    PRINTB(NRF_ADC, CONFIG, REFSEL, 5);
    PRINTB(NRF_ADC, CONFIG, REFSEL, 6);
    PRINTB(NRF_ADC, CONFIG, PSEL, 8);
    PRINTB(NRF_ADC, CONFIG, PSEL, 9);
    PRINTB(NRF_ADC, CONFIG, PSEL, 10);
    PRINTB(NRF_ADC, CONFIG, PSEL, 11);
    PRINTB(NRF_ADC, CONFIG, PSEL, 12);
    PRINTB(NRF_ADC, CONFIG, PSEL, 13);
    PRINTB(NRF_ADC, CONFIG, PSEL, 14);
    PRINTB(NRF_ADC, CONFIG, PSEL, 15);
    PRINTB(NRF_ADC, CONFIG, EXTREFSEL, 16);
    PRINTB(NRF_ADC, CONFIG, EXTREFSEL, 17);
    PRINTH(NRF_ADC, RESULT);

    PRINTHEAD("NRF_FICR - Factory information configuration");
    PRINTH(NRF_FICR, CODEPAGESIZE);
    PRINTH(NRF_FICR, CODESIZE);
    PRINTH(NRF_FICR, CLENR0);
    PRINTH(NRF_FICR, PPFC);
    PRINTH(NRF_FICR, NUMRAMBLOCK);
    PRINTH(NRF_FICR, SIZERAMBLOCKS);
    PRINTH(NRF_FICR, CONFIGID);
    //PRINTH(NRF_FICR, DEVICEID);
    //PRINTH(NRF_FICR, ER);
    //PRINTH(NRF_FICR, IR);
    PRINTB(NRF_FICR, DEVICEADDRTYPE, DEVICEADDRTYPE, 0);
    //PRINTH(NRF_FICR, DEVICEADDR);
    PRINTB(NRF_FICR, OVERRIDEEN, NRF_1MBIT, 0);
    PRINTB(NRF_FICR, OVERRIDEEN, BLE_1MBIT, 3);
    //PRINTH(NRF_FICR, NRF_1MBIT);
    //PRINTH(NRF_FICR, BLE_1MBIT);

    PRINTHEAD("NRF_UICR - User information configuration");
    PRINTH(NRF_UICR, CLENR0);
    PRINTH(NRF_UICR, RBPCONF);
    PRINTH(NRF_UICR, XTALFREQ);
    PRINTH(NRF_UICR, FWID);
    PRINTH(NRF_UICR, BOOTLOADERADDR);

    PRINTHEAD("NRF_NVMC - Non volatile memory controller");
    PRINTH(NRF_NVMC, READY);
    PRINTH(NRF_NVMC, CONFIG);
    PRINTH(NRF_NVMC, ERASEPAGE);
    //PRINTH(NRF_NVMC, ERASEALL);
    //PRINTH(NRF_NVMC, ERASEPROTECTEDPAGE);
    //PRINTH(NRF_NVMC, ERASEUICR);

    PRINTHEAD("NRF_MPU - Memory protection unit");
    PRINTH(NRF_MPU, PERR0);
    PRINTH(NRF_MPU, RLENR0);
    PRINTH(NRF_MPU, PROTENSET0);
    PRINTH(NRF_MPU, PROTENSET1);
    PRINTH(NRF_MPU, DISABLEINDEBUG);
    PRINTH(NRF_MPU, PROTBLOCKSIZE);
    PRINTH(NRF_MPU, ENRBDREG);

    return 0;
}
