CC			:= cc
CVERSION	:= c23
CFLAGS		:= -std=$(CVERSION) -Wall -Wextra

RELEASE ?=
ifeq ($(RELEASE), 1)
	CFLAGS 	+= -O2
else
	CFLAGS 	+= -g
endif

SRC_DIR		:= src
OBJ_DIR		:= obj
TARGET 		:= main

SRCS		:= $(wildcard $(SRC_DIR)/*.c)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Arguments for `make run`
ARGS ?=

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	rm -rf $(TARGET) $(OBJ_DIR) *.dSYM

.PHONY: all run clean
