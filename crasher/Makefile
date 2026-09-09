CC := clang
CFLAGS := -O0 -Wall -Wextra
TARGET := crash

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

.PHONY: all run clean
