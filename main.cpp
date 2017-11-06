#include "mbed.h"

Serial pc(UART2_TX, UART2_RX);


 
int main() {

	int first_char_write=0, first_char_read=0;
	int second_char_write=0, second_char_read=0;

	char write_char = '0';


    while (1) {

    /*	if ( test_var == 2) {
    		break;
    	}*/

	    if(pc.writeable()) {
	    	pc._putc(write_char);
	    	first_char_write++;
	    	/*pc._putc('E');
	    	second_char_write++;*/
	    	//pc._putc('S');
	    }
	    while (1)
	    {
			if(pc.readable()) {
				if (pc._getc() == write_char) {
					first_char_read++;
				}
			}
			/*if(pc.readable()) {
				if (pc._getc() == 'E') {
					second_char_read++;
				}
			}*/
			if (first_char_write == first_char_read /*&& second_char_write == second_char_read*/ )
			{

			    if(pc.writeable()) {
			    	write_char++;
			    	if(write_char > 'z')
			    	{
			    		write_char = '0';
			    	}
			    	pc._putc(write_char);
			    	first_char_write++;
			    	/*pc._putc('E');
			    	second_char_write++;*/
			    	//pc._putc('S');
			    }
			}
	    }
    }
}
