#include <stdio.h>
#include <time.h>
#include "bsp.h"
#include "config.h"

#pragma import(__use_no_semihosting_swi)

extern long timeval;

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int ch, FILE *f)
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART */
    if (ch == '\n')  {
        BSP_PutChar(COM, '\r');
    }
    return BSP_PutChar(COM, ch);
}

int fgetc(FILE *f)
{
    int ch = BSP_GetChar(COM);
    return (BSP_PutChar(COM, ch));
}

int ferror(FILE *f)
{
    /* Your implementation of ferror */
    return EOF;
}

void _ttywrch(int ch)
{
    BSP_PutChar(COM, ch);
}

clock_t clock(void)
{
    return timeval;
}

void _clock_init(void)
{
    timeval = 0;
}

FILE *_sys_open(const char *name, int openmode)
{
    return NULL;
}

void _sys_exit(int return_code)
{
label:  goto label;  /* endless loop */
}
