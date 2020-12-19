CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: circular_linked_list.o test_linked_list_main.o
	$(CXX) $(DEBUG) circular_linked_list.o test_linked_list_main.o -o circular_linked_list_main

circular_linked_list.o: circular_linked_list.cpp
	$(CXX) $(CFLAGS) circular_linked_list.cpp

test_linked_list_main.o: test_linked_list_main.cpp
	$(CXX) $(CFLAGS) test_linked_list_main.cpp

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
	gdb ./circular_linked_list_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./circular_linked_list_main

.PHONY: run
run: test
	./circular_linked_list_main

