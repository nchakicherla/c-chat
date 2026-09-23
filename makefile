CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LDLIBS = -lcurl -lcjson

default: clean main
	./main.run

main: main.c
	$(CC) $(CFLAGS) main.c -o main.run $(LDLIBS)

clean:
	rm -f main.run