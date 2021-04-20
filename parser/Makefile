
all: program

program: main.o hash_table.o array.o json.o
	@echo "linking"
	@gcc -o program main.o hash_table.o json.o array.o > /dev/null

hash_table.o: hash_table.c
	@echo "compiling hash_table.c"
	@gcc -c hash_table.c > /dev/null

array.o: array.c
	@echo "compiling array.c"
	@gcc -c array.c > /dev/null

json.o: json.c
	@echo "compiling json.c"
	@gcc -c json.c > /dev/null

main.o: main.c
	@echo "compiling main.c"
	@gcc -c main.c > /dev/null

clean:
	@rm -rf *.o program
