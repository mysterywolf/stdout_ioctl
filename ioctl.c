#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int stdio_ioctl (int __fd, unsigned long int __request, void *args)
{
    struct winsize* p_winsize;

    if(__fd < 0 || __fd > 2)
    {
        errno = ENOTTY;
        return -1;
    }

    p_winsize = (struct winsize*)args;

    switch (__request)
    {
        case TIOCGWINSZ:
            p_winsize->ws_col = 80; /* TODO: get console size*/
            p_winsize->ws_row = 24;
            p_winsize->ws_xpixel = 0;/*unused*/
            p_winsize->ws_ypixel = 0;/*unused*/
            return 0;

        case TIOCSWINSZ:
            printf("\x1b[8;%d;%dt", p_winsize->ws_col, p_winsize->ws_row);
            return 0;

        default:
            errno = EINVAL;
            return -1;
    }
}
