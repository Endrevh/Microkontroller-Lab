#include "gpio.h"
#include "uart.h"



int main() {

    // Configure buttons
	GPIO->PIN_CNF[BTN_A_PIN] = 0;
	GPIO->PIN_CNF[BTN_B_PIN] = 0;

    int sleep = 0;

    uart_init();    
    
    while(1) {

        if(!(GPIO->IN & (1 << BTN_B_PIN))) {
            uart_send('B');
        }

        if(!(GPIO->IN & (1 << BTN_A_PIN))) {
            uart_send('A');
        }
        
        sleep = 10000;
        while(--sleep);
    }
    
    return 0;
}