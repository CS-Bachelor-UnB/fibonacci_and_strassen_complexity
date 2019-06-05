#
# ------------- DEFINES VARIABLES ------------------- #
#
CC = gcc
CFLAGS = -O0 -Wall -Iinclude

#
# ------------- TARGETS DIRECTORIES ---------------- #
#
ROOT_DIR := $(realpath ./)
INCLUDES =./include/fibonacci.h
BIN =./bin/
SOURCE =./src/

# > library paths
# LFALGS = -L./lib

# > custom libraries to link
# LIBS = -lcustom_lib1 -lcustom_lib2 ...

#
# ------------- DEFINES THE EXECUTABLE FILES -------------- #
#
EXECS = fibonacci_main strassen_main
LINKS =  fibonacci_main strassen_main
LIST = $(addprefix $(BIN), $(EXECS))
LIST_LINKS = $(addprefix $(ROOT_DIR)/, $(LINKS))

#
# ------------- DEFINES THE COMPILATION STEPS -------------- #
#
# .PHONY:	depend clean

all: 	$(LIST)
		@echo Source files have been successfully compiled

$(BIN)%:	$(SOURCE)%.c | BIN_DIR
	$(CC) $(INCLUDES) $< $(CFLAGS) -o $@


links:	$(LIST_LINKS)
		@echo Symbolic links for main executables have been created in root folder

$(ROOT_DIR)%:	$(BIN)%
	ln -s $< $@

clean:	$(LIST)
	rm -f $(LIST)

BIN_DIR:
	mkdir -p $(BIN)
