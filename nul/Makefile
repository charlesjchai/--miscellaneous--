CC ?= cc
CFLAGS ?= -O2
TARGET ?= nul

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

.PHONY: all run clean
