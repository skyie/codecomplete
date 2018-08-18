include ../env.mk


TARGET_BIN  = main

all: $(TARGET_BIN)
	#echo "aa"

$(TARGET_BIN): main.o
	# 这里居然有顺序要求,动态库要放到最后!!!
	$(CC) -o $@ $^ -L$(TOP_LIBS)  -ltest1 -I$(TOP_INCS)
	mv $@ $(BUILD_BIN_DIR)

main.o: main.c
	$(CC) $(CFLAGS) -I$(TOP_INCS) -o $@ $^


.PHONY:help

help:
	# @取消命令回显
	@echo "TOP_INCS:" $(TOP_INCS)
	@echo "CC:" $(CC)


.PHNOY:clean
clean:
	rm -f ./*.o
	
