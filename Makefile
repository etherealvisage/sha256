.PHONY: all clean

all: test

test:
	gcc sha256.c test.c -o test -lcrypto

clean:
	rm -f test
