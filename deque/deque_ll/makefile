CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: deque_ll.o test_deque_ll_main.o
	$(CXX) $(DEBUG) deque_ll.o test_deque_ll_main.o -o deque_ll_main

deque_ll.o: deque_ll.cpp
	$(CXX) $(CFLAGS) deque_ll.cpp

test_deque_ll_main.o: test_deque_ll_main.cpp
	$(CXX) $(CFLAGS) test_deque_ll_main.cpp

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
	gdb ./deque_ll_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./deque_ll_main

.PHONY: run
run: test
	./deque_ll_main

