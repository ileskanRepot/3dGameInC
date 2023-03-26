FLAGS = -g -Wall
CC = gcc
INPUT = main.c render.c
OUTPUT = main

all: $(INPUT)
	$(CC) $(FLAGS) $(INPUT) -o $(OUTPUT)

run: $(INPUT) all
	./main

valgrind: $(INPUT) all
	valgrind --leak-check=full ./main
