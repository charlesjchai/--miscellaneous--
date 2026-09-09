CC := clang++
CFLAGS := -std=c++23 -g -Wall
BIN := main

all: $(BIN)

compile: main.cpp
	$(CC) $(CFLAGS) *.cpp -o $(BIN)
run: compile
	./$(BIN)

clean:
	rm -rf $(BIN) *.dSYM

.PHONY: all compile run clean
