
all: ascii_art_printf_hello_world ascii_art_hello_world loop_with_printf_gcc

ascii_art_printf_hello_world:
	gcc -m32 -o ascii_art_printf_hello_world ascii_art_printf_hello_world.S

ascii_art_hello_world:
	gcc -nostdlib -m32 -o ascii_art_hello_world ascii_art_hello_world.S

loop_with_printf_gcc:
	gcc -m32 -o loop_with_printf_gcc loop_with_printf_gcc.c

.PHONY: clean

clean:
	rm -f *.o ascii_art_hello_world ascii_art_printf_hello_world loop_with_printf_gcc
