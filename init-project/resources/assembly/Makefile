CC	:= clang
CFLAGS	:= -arch arm64

SRCS	:= $(wildcard *.s)
OBJS	:= $(SRCS:.s=.o)
TARGET	:= main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
