CPP := gcc
CC := scc
LD := gcc

SOURCES := $(shell find . -name "*.c")
PREPROC_SOURCES := $(SOURCES:.c=.preproc.c)
ASM_SOURCES := $(SOURCES:.c=.s)
PROGRAMS := $(basename $(ASM_SOURCES))

all: $(PROGRAMS)

%: %.c

%.preproc.c: %.c
	$(CPP) -D__SCC__=1 -E -P $< > $@

%.s: %.preproc.c
	$(CC) $< > $@

%: %.s
	$(LD) -static -o $@ $<

clean:
	rm -f $(PROGRAMS)
	rm -f $(PREPROC_SOURCES)
	rm -f $(ASM_SOURCES)