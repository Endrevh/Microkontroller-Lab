#include "gpio.h"
#include "uart.h"
#include <stdio.h>

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}  

int main() {

    // Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

    // Configure buttons
	GPIO->PIN_CNF[BTN_A_PIN] = 0;
	GPIO->PIN_CNF[BTN_B_PIN] = 0;

    int sleep = 0;

    uart_init();    

    iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');

    while(1) {

        if(!(GPIO->IN & (1 << BTN_B_PIN))) {
            uart_send('B');
        }

        if(!(GPIO->IN & (1 << BTN_A_PIN))) {
            uart_send('A');
        }
        
        if(uart_read() != '\0') {
            if(((GPIO->IN) & (111 << 13)) == 0) { //if LED matrix off, turn on
                for(int i = 13; i <= 15; i++) {
                    GPIO->OUTSET = (1 << i);
                }
            }
            else {
                for(int i = 13; i <= 15; i++) {
                    GPIO->OUTCLR = (1 << i);
                }
            }
            
        }
        sleep = 10000;
        while(--sleep);
    }
    
    return 0;
}