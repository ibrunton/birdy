EXE=birdy

VERSION=0.1a

all: $(EXE)

CC=gcc
CFLAGS=-c -g -Wall -lcurl -Wl,--hash-style=gnu -Wl,--as-needed -DVERSION=\"$(VERSION)\"
LDFLAGS=
SRC=birdy.c config.c options.c twitter.c window.c
OBJ=$(SRC:.c=.o)

$(EXE): $(OBJ)
	$(CC) -Wl,--start-group $(OBJ) -Wl,--end-group -o $@

.c.o:
	$(CC) $(CFLAGS)  $< -o $@

clean:
	rm -rf *.o $(EXE)
