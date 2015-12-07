



CUR_DIR = $(shell pwd)
CC = gcc
CFLAGS = -g 

SUB_DIR = .
SRCS = $(foreach dir, $(SUB_DIR), $(wildcard $(dir)/*.c))

OBJS = $(patsubst %.c, %.o, $(notdir $(SRC)))
#另一种写法效果同上 
#OBJS = $(目录名:%.c=%.o)
INC = -I$(PROG_DIR)/src/include -I$(PROG_DIR)/src/include/test
DYNLIB_PATH = 
SLIB_PATH = 

all : $(OBJS)
	$(CC) $(CFLAGS) $(INC)  -o $@ -c $< 




.PHONY : clean
clean :
	rm -f $(CUR_DIR)/*.o

