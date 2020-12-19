CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: Bst.o test_Bst_main.o
	$(CXX) $(DEBUG) Bst.o test_Bst_main.o -o Bst_main

Bst.o: Bst.cpp
	$(CXX) $(CFLAGS) Bst.cpp

test_Bst_main.o: test_Bst_main.cpp
	$(CXX) $(CFLAGS) test_Bst_main.cpp

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
	gdb ./Bst_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./Bst_main

.PHONY: run
run: test
	./Bst_main


