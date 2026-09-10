CC 		:= cc
CFLAGS 		:= -std=c23 -g -Wall -Wextra
RELEASEFLAGS 	:= -std=c23 -O2
TARGET 		:= main

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
release: *.c
	$(CC) $(RELEASEFLAGS) $^ -o $(TARGET)
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

.PHONY: all run release clean
