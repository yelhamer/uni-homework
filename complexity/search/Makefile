CC = gcc
PARAMS = -Wall -g

.PHONY: all cleanup

bin/nontrie.o: src/non_trie.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/trie.o: src/trie.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/minmax.o: src/minmax.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/main_search.o: src/main_search.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/main_minmax.o: src/main_minmax.c headers/common.h
	$(CC) -o $@ -c $(PARAMS) $<


bin/search: bin/nontrie.o bin/trie.o bin/main_search.o
	$(CC) -o bin/final $(PARAMS) $^

bin/minmax: bin/minmax.o bin/main_minmax.o
	$(CC) -o bin/final $(PARAMS) $^

all: bin/search bin/minmax
	echo "Build completed successfully"

cleanup:
	rm -rf bin && mkdir bin
