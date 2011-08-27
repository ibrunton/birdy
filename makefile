EXE=birdy

VERSION=0.1a

all: $(EXE)

CC=gcc
CFLAGS=-c -g -Wall `pkg-config --libs --cflags gtk+-2.0` -lcurl\
	-Wl,--hash-style=gnu -Wl,--as-needed -DVERSION=\"$(VERSION)\"
LDFLAGS=`pkg-config --libs gtk+-2.0`
DESTDIR=
PREFIX=/usr/local
SRC=birdy.c config.c options.c twitter.c window.c
OBJ=$(SRC:.c=.o)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) -Wl,--start-group $(OBJ) -Wl,--end-group -o $@

.c.o:
	$(CC) $(CFLAGS)  $< -o $@

install: all
	install -D -m 755 -o root -g root birdy $(DESTDIR)$(PREFIX)/bin/birdy
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man1
	sed "s/VERSION/$(VERSION)/g" birdy.1 > $(DESTDIR)$(PREFIX)/share/man/man1/birdy.1
	chmod 655 $(DESTDIR)$(PREFIX)/share/man/man1/sxiv.1

clean:
	rm -rf *.o $(EXE)
