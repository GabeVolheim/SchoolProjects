COMPILER = gcc
OPTIONS = -Wall
PROGRAM = p2.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): p2.c
	$(COMPILER) $(OPTIONS) p2.c -o $(PROGRAM)

clean:
	rm *.out
