#include "uart_v2.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int fd, len;
char text[20];
struct termios options;

int uart_init(void){
   fd = open("/dev/serial0", O_RDWR | O_NDELAY | O_NOCTTY);
   
   if (fd < 0) {
      perror("Error opening");
      return -1;
   }
   options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
   options.c_iflag = IGNPAR;
   options.c_oflag = 0;
   options.c_lflag = 0;
   
   // applies settings
   tcflush(fd, TCIFLUSH);
   tcsetattr(fd, TCSANOW, &options);
   return 1; 
}

void uart_write(char message[20]){
   // write to serial port
   sprintf(text, "%s", message);
   len = strlen(text)+1;
   len = write(fd, text, len);
}
