https://www.man7.org/linux/man-pages/man4/tty_ioctl.4.html

#include <sys/ioctl.h>
#include <unistd.h>

        struct winsize window;
        window.ws_col = 10;
        window.ws_row = 10;
        ioctl(STDOUT_FILENO, TIOCSWINSZ, &window);