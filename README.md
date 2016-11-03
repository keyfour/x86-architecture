
    ██╗  ██╗ █████╗  ██████╗        █████╗ ██████╗  ██████╗██╗  ██╗
    ╚██╗██╔╝██╔══██╗██╔════╝       ██╔══██╗██╔══██╗██╔════╝██║  ██║
     ╚███╔╝ ╚█████╔╝███████╗ █████╗███████║██████╔╝██║     ███████║
     ██╔██╗ ██╔══██╗██╔═══██╗╚════╝██╔══██║██╔══██╗██║     ██╔══██║
    ██╔╝ ██╗╚█████╔╝╚██████╔╝      ██║  ██║██║  ██║╚██████╗██║  ██║
    ╚═╝  ╚═╝ ╚════╝  ╚═════╝       ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝

This examples are written in order to be under the hands of as reminder of basic concepts.
They are **do not** claim to be learning course and implemented for personal use. If
you find them useful for yourself, please write what you think about it to my [email][1].

# ASCII Art "Hello World!"

Why ASCII Art and not just traditional string? I don't know. Just for fun!

There are two examples written on x86 assembly language for GNU assembler:

* ascii_art_hello_world.Si [ [src][2] ]
* ascii_art_printf_hello_world.S [ [src][3] ]

## Compile

For program compilation just run in command shell

```Bash
cd /path/to/your/projects/x86-architecture
make
```

## Run

For standalone assembly example run

```Bash
/path/to/your/projects/x86-architecture/ascii_art_hello_world
```

For running example with glibc printf function call need to run

```Bash
/path/to/your/projects/x86-architecture/ascii_art_printf_hello_world
```
## Run on Android Device

Requiremetns:

* Android x86 device or x86 Atom Image Emulator
* Developer mode must be **on** on connected device or emulator


```Bash
export ADB=$PATH_TO_YOUR_ADB; ./run_on_android.sh ascii_art_hello_world
```

## Clean

From project directory run

```bash
make clean
```

## Output of program

     ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄            ▄▄▄▄▄▄▄▄▄▄▄       ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄   ▄
    ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░▌ ▐░▌
    ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌     ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌
    ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌
    ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌   ▄   ▐░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌          ▐░▌       ▐░▌▐░▌
    ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌  ▐░▌  ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌       ▐░▌▐░▌
    ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌ ▐░▌░▌ ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀█░█▀▀ ▐░▌          ▐░▌       ▐░▌▐░▌
    ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌▐░▌ ▐░▌▐░▌▐░▌       ▐░▌▐░▌     ▐░▌  ▐░▌          ▐░▌       ▐░▌ ▀
    ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌     ▐░▌░▌   ▐░▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌ ▄
    ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░▌
     ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀


[1]: mailto://keyfour13@gmail.com  "Aleksandr Karpov keyfour13@gmail.com"
[2]: ascii_art_hello_world.S "Source"
[3]: ascii_art_printf_hello_world.S "Source"
