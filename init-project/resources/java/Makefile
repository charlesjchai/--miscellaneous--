JC := javac
JVM := java
JFLAGS := -g -d

SRC := src
OUT := out

# Find all .java files
SOURCES := $(wildcard $(SRC)/*.java)

# Default is compile
all: compile

# Compile .java files in SRC to .class files in OUT
compile:
	$(JC) $(JFLAGS) $(OUT) $(SRC)/*.java

run: compile
	$(JVM) -cp $(OUT) Main

clean:
	rm -rf $(OUT)

.PHONY: all compile run clean
