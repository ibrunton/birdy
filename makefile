all: birdy

VERSION=0.1a

CC=gcc
CFLAGS=-c -g -Wall -lcurl -Wl,--hash-style=gnu -Wl,--as-needed -DVERSION=\"$(VERSION)\"
LDFLAGS=
SRC=birdy.c config.c options.c
OBJ=$(SRC:.c=.o)

birdy: $(OBJ)
	$(CC) -Wl,--start-group $(OBJ) -Wl,--end-group -o $@

.c.o:
	$(CC) $(CFLAGS)  $< -o $@

clean:
	rm -rf *.o $(EXE)
