/* 2008 POSIX standard */
#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stddef.h>
#include <unistd.h>

#define BUF_SIZE (1u << 20)

/* Static stuff is faster (bss) */
static char buf[BUF_SIZE];

int main(void) {
    while (1) {
        const char *p = buf;
        size_t remainder = BUF_SIZE;

        while (remainder != 0) {
            ssize_t n = write(STDOUT_FILENO, p, remainder);
            if (n < 0) {
                if (errno == EINTR) /* Ctrl-c */
                    continue;
                return 1; /* e.g. EPIPE (broken pipe) */
            }
            p += n;
            remainder -= (size_t)n;
        }
    }
}
