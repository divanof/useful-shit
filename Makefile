 
TOPDIR := $(shell /bin/pwd)
INCDIR := $(TOPDIR)

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

CC = $(CROSS_COMPILE)gcc
STRIP = $(CROSS_COMPILE)strip
CFLAGS += -Wall -I$(INCDIR) -O2

export CC STRIP CFLAGS TOPDIR INCDIR

CFLAGS += -fPIC

all: $(OBJECTS)
	@$(MAKE) -C tests

clean:
	@rm -vf $(OBJECTS)
	@$(MAKE) clean -C tests

cleanall:
	@rm -vf $(OBJECTS)
	@$(MAKE) cleanall -C tests
