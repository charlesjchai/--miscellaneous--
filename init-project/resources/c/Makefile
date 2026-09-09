CC := clang
CFLAGS := -std=c23 -g -Wall
BIN := main

all: $(BIN)

compile: main.c
	$(CC) $(CFLAGS) *.c -o $(BIN)
run: compile
	./$(BIN)

clean:
	rm -rf $(BIN) *.dSYM

.PHONY: all compile run clean
