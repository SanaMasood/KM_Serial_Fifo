#include "mbed.h"

Serial pc(UART2_TX, UART2_RX);


int main() {

	
	pc.baud (19200);
    pc.printf("Echoes back to the screen anything you type\n");

    while(1) {
    	pc.putc(pc.getc());
    }
}
