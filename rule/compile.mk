#通用编译参数

CC = gcc
CFLAGS = -Werror -g -O2
INCLUDE = $(TOP_DIR)/include
LD_FLAGS = -L$(TOP_DIR)/lib -lhello


SRCS = $(wildcard ./*c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

%.o:%.c
	$(CC) $(INCLUDE) $(CFLAGS) -o ./obj/$@ -c $<


