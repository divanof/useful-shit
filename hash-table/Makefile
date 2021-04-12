
all: program

program: test.o hash_table.o
	@echo "linking"
	@gcc -o program test.o hash_table.o > /dev/null

test.o: test.c
	@echo "compiling test.c"
	@gcc -c test.c > /dev/null

array.o: hash_table.c
	@echo "compiling hash_table.c"
	@gcc -c hash_table.c > /dev/null

clean:
	@rm test.o hash_table.o program
