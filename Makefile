
all: ascii_art_printf_hello_world ascii_art_hello_world

ascii_art_printf_hello_world:
	gcc -m32 -o ascii_art_printf_hello_world ascii_art_printf_hello_world.S

ascii_art_hello_world:
	gcc -nostdlib -m32 -o ascii_art_hello_world ascii_art_hello_world.S

.PHONY: clean

clean:
	rm -f *.o ascii_art_hello_world ascii_art_printf_hello_world
