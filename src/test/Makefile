

export PROG_DIR = $(shell pwd)/../..

CC = gcc
CFLAGS = -g -Werror

SRCS = $(wildcard *.c)
OBJS = $(patsubst *.c, *.o, $(SRCS))
INC = -I$(PROG_DIR)/src/include -I$(PROG_DIR)/src/include/test
DYNLIB_PATH = 
SLIB_PATH = 

PROG = main

%.o : %.c
	$(CC) $(CFLAGS) $(INC)  -c $< 


all : $(PROG)
	$(CC) -o $@ $(OBJS)

.PHONY : show

show :
	@echo "PROG_DIR=" + $(PROG+DIR)
	@echo "SRCS=" + $(SRCS)
	@echo "OBJS=" + $(OBJS)
