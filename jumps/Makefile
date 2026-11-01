CC ?= cc
CFLAGS ?= -O3 -std=c89
TARGET ?= jumps
PREFIX ?= /usr/local

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
run: $(TARGET)
	./$(TARGET)

link: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/games
	ln -sf $(CURDIR)/$(TARGET) $(DESTDIR)$(PREFIX)/games/$(TARGET)
unlink:
	rm -f $(DESTDIR)$(PREFIX)/games/$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

.PHONY: all run clean link unlink
