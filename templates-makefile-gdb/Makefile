all: a.out	

Base.o: Base.cpp Base.h
	g++ -Wall -Wextra -pedantic -Weffc++ -g -O0 -std=c++2a -c Base.cpp

Derived.o: Derived.cpp Derived.h Base.h
	g++ -Wall -Wextra -pedantic -Weffc++ -g -O0 -std=c++2a -c Derived.cpp

main.o: main.cpp Base.h Derived.h
	g++ -Wall -Wextra -pedantic -Weffc++ -g -O0 -std=c++2a -c main.cpp

a.out: Base.o main.o Derived.o
	g++ -Wall -Wextra -pedantic -Weffc++ -g -O0 -std=c++2a *.o

run: all
	./a.out

clean:
	rm -f *.o a.out

gdb: all
	gdb ./a.out