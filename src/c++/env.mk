TOP_DIR = /home/share/codecomplete/src/c++
BUILD_DIR = $(TOP_DIR)/build
BUILD_LIB_DIR = $(TOP_DIR)/build/lib
BUILD_BIN_DIR = $(TOP_DIR)/build/bin
BUILD_CONF_DIR = $(TOP_DIR)/build/conf
BUILD_SCRIPT_DIR = $(TOP_DIR)/build/script




TOP_INCS += $(TOP_DIR)/include
TOP_LIBS := $(BUILD_LIB_DIR)

export LD_LIBRARY_PATH=$(TOP_LIBS)

CC = gcc
CFLAGS = -g -c # -Wall
SHARE_FLAGS = -fPIC

LD_FLAGS = -shared


BUILD_DIR = $(TOP_DIR)/build
BUILD_LIB_DIR = $(TOP_DIR)/build/lib
BUILD_BIN_DIR = $(TOP_DIR)/build/bin
BUILD_CONF_DIR = $(TOP_DIR)/build/conf
BUILD_SCRIPT_DIR = $(TOP_DIR)/build/script


