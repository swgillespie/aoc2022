#ifndef __AOC_H__
#define __AOC_H__

#ifdef __SCC__
char*
gets(char* str);

int
puts(char* str);

int
strlen(char* str);

int
printf(char* format, ...);

int
atoi(char* str);
#else
#include <stdio.h>
#endif

#endif /* __AOC_H__ */
