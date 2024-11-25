OS = $(shell uname)
ifeq ($(OS),Darwin)
        FLAGS = -Wall -Werror -Wextra -std=c++17 
        LIBS = -lgtest -pthread
        M = 
else ifeq ($(OS),Linux)
        FLAGS = -Wall -Werror -Wextra -std=c++17
        LIBS =  -lgtest -pthread
        M = -lm
endif

CPP             := g++
S21             := s21_containers
SRC 			:= s21_containers.h
GCOV_FLAGS 		:= -fprofile-arcs -ftest-coverage
TREE			:= s21_AVL_Tree/s21_AVL_Tree.hpp
MAP				:= s21_map/s21_map.hpp
TEST 			:= test/s21_test.cpp
TEST_RES		:= test_obj
DEBUG			:= -D "DEBUG"	
LIB				:= ar rcs

all: $(S21).a

build_directory: 
	mkdir build

$(S21).a: build_directory $(SRC) $(MAP) $(TREE)
	$(CPP)  $(MAP) $(TREE)	-o 	build/Map.o
	$(LIB) $(S21).a build/*.o

test: clean $(S21).a
	$(CPP)  $(TEST) -o $(TEST_RES) $(LIBS)
	./$(TEST_RES)

test_debug: clean build_directory $(MAP) $(TREE)
	$(CPP)  $(DEBUG) $(MAP) $(TREE)	-o 	build/Map.o
	$(LIB) $(S21).a build/*.o
	$(CPP) $(DEBUG)  $(TEST) -o $(TEST_RES) $(LIBS)
	./$(TEST_RES)

valgrind: clean test
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks_log.txt ./$(TEST_RES)
	grep -e "ERROR SUMMARY: 1" leaks_log.txt -n > all_err.txt
	grep -e "fn" leaks_log.txt -n > fn_err.txt

clean:
	rm -rf -r build/
	rm -rf *.a
	rm -rf *.o
	rm -rf $(TEST_RES)
	rm -rf leaks_log.txt fn_err.txt all_err.txt
	rm -rf test_obj