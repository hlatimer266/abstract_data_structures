CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: deque_arr.o test_deque_arr_main.o
	$(CXX) $(DEBUG) deque_arr.o test_deque_arr_main.o -o deque_arr_main

deque_arr.o: deque_arr.cpp
	$(CXX) $(CFLAGS) deque_arr.cpp

test_deque_arr_main.o: test_deque_arr_main.cpp
	$(CXX) $(CFLAGS) test_deque_arr_main.cpp

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
	gdb ./deque_arr_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./deque_arr_main

.PHONY: run
run: test
	./deque_arr_main

