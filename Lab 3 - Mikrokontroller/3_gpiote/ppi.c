#include "ppi.h"
#include "gpiote.h"

void ppi_setup() 
{
    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->IN[0]);
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->OUT[1]);

    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[2]);

    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[3]);

    
    PPI->CHENSET = (1 << 0);
    PPI->CHENSET = (1 << 1);
    PPI->CHENSET = (1 << 2);
}