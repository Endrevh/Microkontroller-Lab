#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main() {

    // Configure LED Matrix
	for(int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

    gpiote_setup();
    ppi_setup();

    int sleep = 0;

    while(1) {
    
    
        sleep = 10000;
        while(--sleep);
    }

    return 0;
}