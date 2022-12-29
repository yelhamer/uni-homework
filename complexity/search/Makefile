CC = gcc
PARAMS = -Wall -g

.PHONY: all cleanup

bin/nontrie.o: src/non_trie.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/trie.o: src/trie.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/main.o: src/main.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

all: bin/nontrie.o bin/trie.o bin/main.o
	$(CC) -o bin/final $(PARAMS) $^

cleanup:
	rm -rf bin && mkdir bin
