.PHONY: clean run compile

run: main
	@./main

compile main: main.o random.o
	@gcc -o main main.o random.o

main.o: main.c random.h
	@gcc -c main.c

random.o: random.c random.h
	@gcc -c random.c

clean:
	@rm *.o main
