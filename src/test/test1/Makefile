

CUR_DIR = $(shell pwd)
CC = gcc
LD = gcc
CFLAGS = -g 

SUB_DIR = test1 test2 .
SRCS = $(foreach dir, $(SUB_DIR), $(wildcard $(dir)/*.c))

OBJS = $(patsubst %.c, %.o, $(notdir $(SRCS)))
#另一种写法效果同上 
#OBJS = $(目录名:%.c=%.o)
INC = -I$(PROG_DIR)/src/include -I$(PROG_DIR)/src/include/test
DYNLIB_PATH = 
SLIB_PATH = 

all : $(OBJS)
	$(CC) $(CFLAGS) $(INC)  -o $< -c $^




.PHONY : show

show :
	@echo "PROG_DIR="  $(PROG_DIR)
	@echo "SRCS="  $(SRCS)
	@echo "OBJS="  $(OBJS)
	@echo "CUR_DIR=" $(CUR_DIR)