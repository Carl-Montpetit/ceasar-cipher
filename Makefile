# CONSTANTS
EXE = cesar
RUN = ./cesar
INPUT_FILE = examples/test-1.txt
OUTPUT_FILE = examples/output.txt
C = cesar.c
ALL_C = *.c
H = cesar.h
O = cesar.o
ALL_O = *.o
CC = gcc
DEBUG = -g
CREATE_EXE = -o
COMPILE = -c
LINK = -L
WARNINGS = -Wextra
VERSION11 = -std=c11
RUN_TESTS = bats
TESTS_LIST = check.bats
# RULES
all: $(EXE) 
cesar: $(O)
	$(CC) $(DEBUG) $(CREATE_EXE) $(EXE) $(VERSION11) $(WARNINGS) $(C)
cesar.o: $(C)
	$(CC) $(COMPILE) $(C)
build: $(C)
	$(CC) $(COMPILE) $(VERSION11) $(WARNINGS) $(C)
link: $(C)
	$(CC) $(LINK) $(H) $(C) 
test: $(TESTS_LIST)
	$(RUN_TESTS) $(TESTS_LIST)
start: $(EXE)
	./cesar INPUT_FILE OUTPUT_FILE
clean: 
	rm -f $(EXE) $(ALL_O)