# Make for C compiling

DEBUG=y

ZLIB=/home/zamek/c/zamek_lib

USE_UTIL=y
USE_STR=y
SRC=.

include $(ZLIB)/Makefile.in

OBJS=$(patsubst $(SRC)/%.c,$(OBJ_ROOT)/$(ARCH)/%.o,$(wildcard $(SRC)/*.c))
BIN_NAME=$(BIN_ROOT)/$(ARCH)/test

$(info ==============================================)
$(info arch:$(ARCH))
$(info objs:$(OBJS))
$(info bin_root:$(BIN_ROOT))
$(info obj_root:$(OBJ_ROOT))
$(info bin_name:$(BIN_NAME))
$(info include:$(INCLUDE_DIR))
$(info libpath:$(LIB_PATH))
$(info lib: $(LIB))
$(info ==============================================)

$(BIN_NAME): $(OBJ_ROOT)/$(ARCH) $(BIN_ROOT)/Debug $(OBJS)
	$(CC) -o$(BIN_NAME) $(OBJS) $(LIB_PATH) $(LIB) $(CFLAGS)

$(OBJ_ROOT)/$(ARCH)/%.o:%.c
	$(CC) -c -fPIC $< -o $@ $(CFLAGS) $(INCLUDE_DIR)

$(BIN_ROOT)/Debug:$(BIN_ROOT)
		mkdir $(BIN_ROOT)/Debug

Debug:$(BIN_NAME)

Release:$(BIN_NAME)

run:$(BIN_NAME)
	$(BIN_NAME)

.PHONY:run





