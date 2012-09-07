PREFIX?=/opt/local

all:
	gcc fileflags.c -o fileflags

clean:
	rm -f fileflags

install: all
	mkdir -p "$(PREFIX)/bin"
	cp -f fileflags "$(PREFIX)/bin/"

uninstall:
	rm -f "$(PREFIX)/bin/fileflags"

.PHONY: clean install uninstall
