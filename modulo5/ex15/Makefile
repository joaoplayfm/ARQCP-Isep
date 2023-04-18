main: main.o 
	gcc -g -Wall main.o  -o main

main.o: main.c 
	gcc -g -Wall -c main.c
	  
clean:
	rm -f *.o main

debug: main
	gdb -tui ./main

vg: main
	valgrind ./main
	
run: main
	./main