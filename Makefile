#
# ------------- DEFINES VARIABLES ------------------- #
#
CXX = g++
CXXFLAGS = -O3 -Iinclude

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
.PHONY: all clean links

all: 	$(LIST)
		@echo Source files have been successfully compiled

$(BIN)strassen_main: $(SOURCE)strassen.c | BIN_DIR
	$(CC)  $< -o $@

$(BIN)fibonacci_main:	$(SOURCE)fibonacci_main.cpp $(SOURCE)fibonacci_matrix.cpp $(SOURCE)fibonacci_recursive.cpp $(SOURCE)fibonacci_loop.cpp $(SOURCE)fibonacci_formula.cpp  | BIN_DIR
	$(CXX) $(INCLUDES) $(SOURCE)fibonacci_main.cpp $(SOURCE)fibonacci_matrix.cpp $(SOURCE)fibonacci_recursive.cpp $(SOURCE)fibonacci_loop.cpp $(SOURCE)fibonacci_formula.cpp  $(CXXFLAGS) -o $@

links:	$(LIST_LINKS)
		@echo Symbolic links for main executables have been created in root folder

$(ROOT_DIR)%:	$(BIN)%
	ln -s $< $@

clean:	$(LIST)
	rm -f $(LIST)

BIN_DIR:
	mkdir -p $(BIN)
