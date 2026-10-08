CC ?= cc
CFLAGS ?= -O2
TARGET ?= nul
PREFIX ?= /usr/local

all: $(TARGET)

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@
run: $(TARGET)
	./$(TARGET)

link: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	ln -sf $(CURDIR)/$(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
unlink:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -rf $(TARGET) *.dSYM

.PHONY: all run clean link unlink
