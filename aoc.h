#ifndef __AOC_H__
#define __AOC_H__

#ifdef __SCC__

extern void* stdin;
extern void* stdout;

char*
fgets(char* s, int size, void* stream);

int
puts(char* str);

int
strlen(char* str);

int
printf(char* format, ...);

int
atoi(char* str);

void
memset(void* s, int c, int n);

int
sscanf(char* str, char* format, ...);

int
fputc(int c, void* stream);

void*
memcpy(void* dest, void* str, int n);

#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#endif /* __AOC_H__ */
