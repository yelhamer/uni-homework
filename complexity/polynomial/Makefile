CC = gcc
PARAMS = -Wall -g

.PHONY: all cleanup

bin/matrix_common.o: src/matrix_common.c headers/matrix_common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/matrix_product.o: src/matrix_product.c headers/matrix_common.h
	$(CC) -o $@ -c $(PARAMS) $<

bin/matrix_product: bin/matrix_product.o bin/matrix_common.o
	$(CC) -o $@ $(PARAMS) $^

all: bin/matrix_product
	echo "Build completed successfully"

cleanup:
	rm -rf bin && mkdir bin
