COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): Date.cpp main.cpp calcDays.cpp
	$(COMPILER) $(OPTIONS) Date.cpp main.cpp calcDays.cpp -o $(PROGRAM)

clean:
	rm *.out
