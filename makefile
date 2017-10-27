VERSION:=0.0.1

.PHONY: install
install:
	make -C release
	sudo mkdir /usr/local/lib/libmips
	sudo mv release/libmips.a /usr/local/lib/libmips
	