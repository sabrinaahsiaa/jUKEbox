extern int fd, len;
extern char text[20];

extern struct termios options;

// initialize UART to have a baud rate of 115200
int uart_init(void);

// allows a max input string of 15 chars
void uart_write(char message[20]);
