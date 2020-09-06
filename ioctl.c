#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

/*
EBADF d is not a valid descriptor.
EFAULT argp references an inaccessible memory area.
EINVAL Request or argp is not valid.
ENOTTY d is not associated with a character special device.
ENOTTY The specified request does not apply to the kind of object that the descriptor d references.
*/

int stdout_ioctl (int __fd, unsigned long int __request, void *args)
{
    struct winsize* p_winsize;

    if(__fd != STDOUT_FILENO)
    {
        errno = ENOTTY;
        return -1;
    }

    p_winsize = (struct winsize*)args;

    switch (__request)
    {
        case TIOCGWINSZ:
            p_winsize->ws_col = 80;
            p_winsize->ws_row = 24;
            p_winsize->ws_xpixel = 0;/*unused*/
            p_winsize->ws_ypixel = 0;/*unused*/
            return 0;

        case TIOCSWINSZ:
            printf("\e[8;%d;%dt", p_winsize->ws_col, p_winsize->ws_row);
            return 0;

        default:
            errno = EINVAL;
            return -1;
    }
}
