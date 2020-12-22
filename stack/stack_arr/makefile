CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: stack_arr.o test_stack_arr_main.o
	$(CXX) $(DEBUG) stack_arr.o test_stack_arr_main.o -o stack_arr_main

stack_arr.o: stack_arr.cpp
	$(CXX) $(CFLAGS) stack_arr.cpp

test_stack_arr_main.o: test_stack_arr_main.cpp
	$(CXX) $(CFLAGS) test_stack_arr_main.cpp

clean:
	$(RM) test *.o *~D

# run from root dir of the project
.PHONY: build_docker
build_docker:
	docker build -t gdb .

# run from root dir of the project
.PHONY: run_docker
run_docker:
	docker run -it -v $(shell pwd)/:/tmp gdb:latest sh	

# will only run in docker container (all files in /tmp dir)
.PHONY: debug
debug: clean test
	gdb ./stack_arr_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./stack_arr_main

.PHONY: run
run: test
	./stack_arr_main


