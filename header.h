#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define RESET "\033[0m"
#define RED "\033[31m"               /* Red */
#define GREEN "\033[32m"             /* Green */
#define YELLOW "\033[33m"            /* Yellow */
#define BOLDRED "\033[1m\033[31m"    /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"  /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define sleep           \
    {                   \
        sleep(1);       \
        fflush(stdout); \
    }
int comp(char *, char *, char *, int *);
void rem(char *, int);
void red(char);
void green(char);
void yellow(char);
#elif _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#define RESET "\033[0m"
#define RED "\033[31m"               /* Red */
#define GREEN "\033[32m"             /* Green */
#define YELLOW "\033[33m"            /* Yellow */
#define BOLDRED "\033[1m\033[31m"    /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"  /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define sleep Sleep(1000)
int comp(char *, char *, char *, int *);
void rem(char *, int);
void red(char);
void green(char);
void yellow(char);
#endif
