CC   = gcc
NAME = test

INCLUDE_DIR = ./include
SRC_DIR     = ./src

BUILD_DIR   = ./build

SRCS = $(shell find $(SRC_DIR) -name *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

BUILT_OBJS = $(patsubst %, $(BUILD_DIR)/%, $(notdir $(OBJS)))

LIBS   = -lm
CFLAGS = -Wall -I$(INCLUDE_DIR)/

.PHONY: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(BUILT_OBJS) -o $(BUILD_DIR)/$@ $(LIBS)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $(BUILD_DIR)/$(@F) $(LIBS)

clean:
	rm $(BUILD_DIR)/*
