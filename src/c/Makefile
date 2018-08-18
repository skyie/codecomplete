include env.mk

MAIN_TARGET = main
DIRS = lib src


all: PRE_BUILD DIR


PRE_BUILD:
	[ -e $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	[ -e $(BUILD_BIN_DIR) ] || mkdir -p $(BUILD_BIN_DIR)
	[ -e $(BUILD_LIB_DIR) ] || mkdir -p $(BUILD_LIB_DIR)
	[ -e $(BUILD_CONF_DIR) ] || mkdir -p $(BUILD_CONF_DIR)
	[ -e $(BUILD_SCRIPT_DIR) ] || mkdir -p $(BUILD_SCRIPT_DIR)



DIR:
	# 注意不能写$$(one),要把括号去掉
	for one in $(DIRS); do  make -C $$one || exit 1;done
	@echo "------------"

.PHONY: clean
clean:
	rm -fr $(BUILD_DIR)
	for one in $(DIRS);do make -C $$one clean;done

