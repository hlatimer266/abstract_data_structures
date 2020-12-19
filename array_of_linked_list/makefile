CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: linked_list.o array_of_ll.o test_main.o
	$(CXX) $(DEBUG) linked_list.o array_of_ll.o test_main.o -o main

linked_list.o: linked_list.cpp
	$(CXX) $(CFLAGS) linked_list.cpp

array_of_ll.o: array_of_ll.cpp
	$(CXX) $(CFLAGS) array_of_ll.cpp

test_main.o: test_main.cpp
	$(CXX) $(CFLAGS) test_main.cpp

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
	gdb ./main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./main

.PHONY: run
run: test
	./main

