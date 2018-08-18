include ../env.mk

.PHONY: all



CC = gcc
CFLAGS = -g -c # -Wall
SHARE_FLAGS = -fPIC

LD_FLAGS = -shared 



all : libtest2.so libtest1.so

LIBTEST1 = libtest1.so

LIBTEST2 = libtest2.so


libtest1.so : libtest1.o
	$(CC)  -I$(TOP_LIBS) -o $@ $^  $(LD_FLAGS) -L$(TOP_LIBS) -Wl,-rpath=$(TOP_LIBS) -ltest2
	cp $@ $(BUILD_LIB_DIR)

libtest1.o : libtest1.c
	$(CC) $(CFLAGS)  $(SHARE_FLAGS) -I$(TOP_INCS) -o $@ $^     

libtest2.so : libtest2.o
	$(CC)  $(LD_FLAGS)   -o $@ $^     
	cp $@ $(BUILD_LIB_DIR)

	
libtest2.o : libtest2.c
	$(CC) $(CFLAGS) $(SHARE_FLAGS) -I$(TOP_INCS) -o $@ $^    




.PHONY: clean
clean:
	rm -f *.so *.o
