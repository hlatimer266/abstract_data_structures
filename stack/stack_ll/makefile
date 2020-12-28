CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: stack_ll.o test_stack_ll_main.o
	$(CXX) $(DEBUG) stack_ll.o test_stack_ll_main.o -o stack_ll_main

stack_ll.o: stack_ll.cpp
	$(CXX) $(CFLAGS) stack_ll.cpp

test_stack_ll_main.o: test_stack_ll_main.cpp
	$(CXX) $(CFLAGS) test_stack_ll_main.cpp

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
	gdb ./stack_ll_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./stack_ll_main

.PHONY: run
run: test
	./stack_ll_main


