#include "uart.h"
#include "gpio.h"
 

void uart_init()
{
    GPIO->PIN_CNF[TGT_TXD_PIN] = 1; //configure TXD_PIN as output
    GPIO->PIN_CNF[TGT_RXD_PIN] = 0; //configure RXD_PIN as input
    
    UART->PSELTXD = TGT_TXD_PIN; //assign TXT_PIN to uart module
    UART->PSELRXD = TGT_RXD_PIN; //assign RXD_PIN to uart module

    UART->BAUDRATE = 0x275000;

    UART->PSELRTS = 0xFFFFFFFF; //disconnect RTS
    UART->PSELCTS = 0xFFFFFFFF; //disconnect CTS

    UART->ENABLE = 4; //enable UART
    UART->STARTRX = 1; //start recieving message
}

void uart_send(char letter) {

    UART->STARTTX = 1;
    UART->TXDRDY = 0;
    
    UART->TXD = letter;

    while(!(UART->TXDRDY)) {
    
    }
    
    UART->TXDRDY = 0;

    UART->STOPTX = 1;
}

char uart_read() {
    UART->RXDRDY = 0;

    char recieved = UART->RXD;


    if(!(recieved)) {
        return '\0';
    } 
    else{
        return recieved;
    }

    UART->RXDRDY = 1;
}