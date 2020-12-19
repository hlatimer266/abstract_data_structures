CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: doubly_linked_list.o test_doubly_linked_list_main.o
	$(CXX) $(DEBUG) doubly_linked_list.o test_doubly_linked_list_main.o -o doubly_linked_list_main

doubly_linked_list.o: doubly_linked_list.cpp
	$(CXX) $(CFLAGS) doubly_linked_list.cpp

test_doubly_linked_list_main.o: test_doubly_linked_list_main.cpp
	$(CXX) $(CFLAGS) test_doubly_linked_list_main.cpp

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
	gdb ./doubly_linked_list_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./doubly_linked_list_main

.PHONY: run
run: test
	./doubly_linked_list_main


