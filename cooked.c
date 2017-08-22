#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
 
struct termios tty_attr_old;
struct termios tty_attr;
int            old_keyboard_mode;
 
int init_terminal()
{
    /* init terminal device to raw mode */
    if(ioctl(0, KDGKBMODE, &old_keyboard_mode) < 0) 
    {
        /* this usually happens when X is running */
        /* Print some error and exit              */
        exit(EXIT_FAILURE);
    }
    tcgetattr(0, &tty_attr_old);
    tty_attr            = tty_attr_old;
    /* turn off buffering, echo and key processing */
    tty_attr.c_lflag   &= ~(ICANON | ECHO | ISIG);
    tty_attr.c_iflag   &= ~(ISTRIP | INLCR | ICRNL | 
                            IGNCR | IXON | IXOFF);
    /* block until 1 key comes in */
    tty_attr.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &tty_attr);
    ioctl(0, KDSKBMODE, K_RAW);
    return 1;
}
