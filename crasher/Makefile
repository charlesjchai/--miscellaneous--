CC ?= cc
CFLAGS := -O0 -Wall -Wextra
TARGET := crash
PREFIX ?= /usr/local

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

link: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	ln -sf $(CURDIR)/$(TARGET) $(DESTDIR)$(PREFIX)/bin/
unlink:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

.PHONY: all run clean link unlink
