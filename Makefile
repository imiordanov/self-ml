CC=g++
FLAGS=-Wall

.PHONY: all main

main:
	${CC} main.cpp ${FLAGS} -o main

clean:
	rm -f a.out main