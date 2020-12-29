CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: hash_table.o test_hash_table_main.o
	$(CXX) $(DEBUG) hash_table.o test_hash_table_main.o -o hash_table_main

hash_table.o: hash_table.cpp
	$(CXX) $(CFLAGS) hash_table.cpp

test_hash_table_main.o: test_hash_table_main.cpp
	$(CXX) $(CFLAGS) test_hash_table_main.cpp

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
	gdb ./hash_table_main

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./hash_table_main

.PHONY: run
run: test
	./hash_table_main


