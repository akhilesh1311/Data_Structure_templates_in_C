OBJECT = graphs.o heaps.o include.o queue.o stack.o string_operations.o trees.o
CC = gcc
VPATH = graphs:heaps:include:queue:stack:string_operations:trees
#GPATH = graphs:heaps:include:queue:stack:string_operations:trees
DEPS = graphs.h heaps.h include.h queue.h stack.h string_operations.h trees.h
#DIR =
#Random Comment  
LDIR = $(PWD)/$(VPATH)/lib
IDIR = $(PWD)/include

.PHONY: trees queue heap stack graph clean

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $<

stack.o: Dynamic_generic_stack.c Dynamic_generic_stack.h
	$(CC) -c -o $@ $<

queue.o: circular_queue_generic.c queue.h
	$(CC) -c -o $@ $<

heap.o: max-minHeap_generic.c
	$(CC) -c -o $@ $<

trees.o: bst.c trees.h
	$(CC) -c -o $@ $<

graph.o: adj_list.c graphs.h
	$(CC) -c -o $@ $<

queue: queue.o
	$(CC) -o $@_out $^

stack: stack.o
	$(CC) -o $@_out $^
	
heap: heap.o
	$(CC) -o $@_out $^

trees: stack.o queue.o trees.o $(DEPS)
	$(CC) -o $@_out $^
	
graph: stack.o queue.o graph.o $(DEPS)
	$(CC) -o $@_out $^
