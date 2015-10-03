#include <cmsis.h>

/* for getpid */
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>

extern int __real_main(void);

int __wrap_main(void)
{
	return __real_main();
}

void _exit(int status)
{
    (void) status;
    while(1) {
        __BKPT(0);
    }
}

int _kill(pid_t pid, int sig)
{
    (void) pid;
    (void) sig;
    errno = EINVAL;
    return -1;
}

pid_t _getpid(void)
{
    return 0;
}
