CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LDLIBS = -lcurl -lcjson

main-build-run: main.run
	valgrind ./main.run

main: main.c
	$(CC) $(CFLAGS) main.c -o main.run $(LDLIBS)

clean:
	rm -f main.run