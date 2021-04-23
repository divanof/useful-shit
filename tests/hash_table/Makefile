
.PHONY: clean cleanall

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
PROGRAM = test
LDFLAGS = -ldl

HASH_TABLE=$(TOPDIR)/hash_table.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS) 
	$(CC) -rdynamic $(OBJECTS) $(HASH_TABLE) -o $@ $(LDFLAGS)
	@echo $(OBJECTS)
clean:
	@rm -fv $(OBJECTS)
cleanall:
	@rm -fv $(OBJECTS) $(PROGRAM)
