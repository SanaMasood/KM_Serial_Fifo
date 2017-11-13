#include "mbed.h"

Serial pc(UART1_TX, UART1_RX);
Serial dev(UART2_TX, UART2_RX);

void callback1() {
	pc._putc(pc._getc());
}

void callback2() {
	dev._putc(dev._getc());
}



int main() {
	pc.attach(&callback1);
	dev.attach(&callback2);

    pc.printf("Echoes back to the screen anything you type\n");
    dev.printf("Echoes back to the screen anything you type\n");


    while(1) {

    }
}
