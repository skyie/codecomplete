include ../env.mk


BIN  = main

all: $(BIN)
	$(CC) -L$(TOP_LIBS) -ltest1 -o $@ $^

BIN: main.o
	$(CC) $(CFLAGS) -I$(TOP_INCS) -o $@ $^
	mv $@ $(BUILD_BIN_DIR)

.PHONY:help

help:
	# @取消命令回显
	@echo "TOP_INCS:" $(TOP_INCS)
	@echo "CC:" $(CC)


.PHNOY:clean
clean:
	rm -f ./*.o
	
