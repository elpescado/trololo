DESTDIR=/usr/bin

.PHONY: install

all: trololo

trololo: trololo.c

install: trololo
	install -o root -m 4755 trololo $(DESTDIR)/trololo

