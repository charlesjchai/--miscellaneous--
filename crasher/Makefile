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

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

.PHONY: all run clean install uninstall
