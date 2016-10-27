
    ██╗  ██╗ █████╗  ██████╗        █████╗ ██████╗  ██████╗██╗  ██╗
    ╚██╗██╔╝██╔══██╗██╔════╝       ██╔══██╗██╔══██╗██╔════╝██║  ██║
     ╚███╔╝ ╚█████╔╝███████╗ █████╗███████║██████╔╝██║     ███████║
     ██╔██╗ ██╔══██╗██╔═══██╗╚════╝██╔══██║██╔══██╗██║     ██╔══██║
    ██╔╝ ██╗╚█████╔╝╚██████╔╝      ██║  ██║██║  ██║╚██████╗██║  ██║
    ╚═╝  ╚═╝ ╚════╝  ╚═════╝       ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝

# Contents

* [Basic Architecture](#basic-architecture)
    * [Bit and Byte Order](#bit-and-byte-order)
        * [Data Structure](#data-structure)
    * [Segmented Adressing](#segmented-addressing)
    * [Modes of Operations](#modes-of-operations)
        * [Protected Mode](#protected-mode)
        * [Real-address Mode](#real-address-mode)
        * [System Management Mode](#system-management-mode)
    * [Memory Models](#memory-models)
        * [Flat memory model](#flat-memory-model)
        * [Segmented memory model](#segmented-memory-model)
        * [Real-address mode memory model](#real-address-mode-memory-model)
    * [Registers](#registers)
        * [General-purpose registers](#general-purpose-registers)
        * [Segment Registers](#segment-registers)
* [Appendix of Tables](#appendix-of-tables)
* [References](#references)
                                                               
#Basic Architecture

## Bit and Byte Order

> “little endian” - the bytes of a word are numbered starting from the least significant byte

### Data Structure

#### Table 1. Bit and Byte Order [ [csv][3] ]

| Highest Address | 32  24  | 23  16  | 15  8   | 7  0    | ← Bit Offset      |                    |
|-----------------|---------|---------|---------|---------|-------------------|--------------------|
|                 | Byte 31 | Byte 30 | Byte 29 | Byte 28 | **28**            |                    |
|                 | Byte 27 | Byte 26 | Byte 25 | Byte 24 | **24**            |                    |
|                 | Byte 23 | Byte 22 | Byte 21 | Byte 20 | **20**            |                    |
|                 | Byte 19 | Byte 18 | Byte 17 | Byte 16 | **16**            |                    |
|                 | Byte 15 | Byte 14 | Byte 13 | Byte 12 | **12**            |                    |
|                 | Byte 11 | Byte 10 | Byte 9  | Byte 8  | **8**             |                    |
|                 | Byte 7  | Byte 6  | Byte 5  | Byte 4  | **4**             |                    |
|                 | Byte 3  | Byte 2  | Byte 1  | Byte 0  | **0**             |                    |
|                 |         |         |         |         | **↑ Byte Offset** | **Lowest Address** |

## Segmented Addressing

There is possible to use *segmented addressing* - a form of addressing where a program may have many
independent address spaces, called **segments**. For example, a program can keep its code (instructions) and stack
in separate segments. Code addresses would always refer to the code space, and stack addresses would always
refer to the stack space.

> Segment-register:Byte-address

## Modes of Operations

### Protected Mode

This mode is the native state of the processor.  A segment can have any size, from 1 byte to 4GB.
The OS defines the size of each segment, and now each segment can have limitations (read, write, execute on or off).
This allows the OS to "protect" the memory. In addition, there are 4 levels of authority (0 to 3, 0 = highest), so,
for example, when a user application runs in level 3, it cannot touch the OS which runs at level 0. Among the
capabilities of protected mode is the ability to directly execute “real-address mode” 8086 software in a protected,
multi-tasking environment. This feature is called virtual-8086 mode, although it is not actually a processor mode.
Virtual-8086 mode is actually a protected mode attribute that can be enabled for any task.

### Real-address Mode

This mode implements the programming environment of the Intel 8086 processor with
extensions (such as the ability to switch to protected or system management mode).
The processor is placed in real-address mode following power-up or a reset. In Real mode,
everything is 16 bits. The entire memory is not accessed with an absolute index from 0,
but it is divided into segments. Each segment represents the actual offset from 0,
multiplied by 16. To this segment, an offset value can be added to refer to a distance
from the start of this segment

### System Management Mode

This mode provides an operating system or executive with a transparent mechanism for
implementing platform-specific functions such as power management and system security.
The processor enters SMM when the external SMM interrupt pin (SMI#) is activated or an SMI is
received from the advanced programmable interrupt controller (APIC).
In SMM, the processor switches to a separate address space while saving the basic context of the currently
running program or task. SMM-specific code may then be executed transparently. Upon returning from SMM,
the processor is placed back into its state prior to the system management interrupt.

## Memory Models

The linear address space can be paged when using the flat or segmented model.

### Flat memory model

                                   ┌────────────────┐
                                   │                │
                                   │                │
     Linear Address                │                │
    ┌────────────────┐             ├────────────────┤
    │                ├────────────▶│                │
    └────────────────┘             ├────────────────┤
                                   │                │
                                   │                │
                          Linear   │                │
                          Address  │                │
                          Space    │                │
                                   └────────────────┘

Memory appears to a program as a single, continuous address space. Code, data, and stacks
are all contained in this address space.

### Segmented memory model

                                                                                       ┌────────────────┐
                                                                                       │                │
                                                                                       │                │
                                                                ┌─────────────────────▶│                │
                                                                │                      │                │
                                                                │                      ├────────────────┤
                                                                │                      │▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓│
                                                        ┌───────┴────────┐             │▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓│
                                                        │                │             ├────────────────┤
                                                        │                │             │                │
                                                   ┌────┴───────────┐    │     ┌──────▶│                │
                                                   │                │    │     │       │                │
                                       Segments    │                │    │     │       │                │
                                              ┌────┴───────────┐    ├────┘     │       ├────────────────┤
                                              │                │    ├──────────┘       │▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓│
                                              │                │    │                  │▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓│
                Offset (effective address)    │                ├────┘                  ├────────────────┤
               ┌────────────────┐             ├────────────────┤             Linear    │                │
               │                ├────────────▶│                │             Address   │                │
    Logical    └────────────────┘             ├────────────────┤             Space     │                │
    Address                                   │                │                       ├────────────────┤
                Segment Selector              │                ├──────────────────────▶│                │
               ┌────────────────┐             │                │                       ├────────────────┤
               │                ├────────────▶└────────────────┘                       │                │
               └────────────────┘                                                      └────────────────┘

Memory appears to a program as a group of independent address spaces
called segments. Code, data, and stacks are typically contained in separate segments. To address a byte in a
segment, a program issues a logical address. This consists of a segment selector and an offset (logical
addresses are often referred to as far pointers). The segment selector identifies the segment to be accessed
and the offset identifies a byte in the address space of the segment.

### Real-address mode memory model

                                                            ┌────────────────┐
                                                            │                │
                                                            │                │
                                                            │                │
                                                            │                │
                                                            ├┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┤
                                                            │                │
                                                            │                │
                                             Linear Address │                │
                                             Space Devided  │                │
                Offset (effective address)   Into Equals    ├┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┤
               ┌────────────────┐            Sized Segments ├────────────────┤
               │                ├──────────────────────────▶│                │
    Logical    └────────────────┘                           ├────────────────┤
    Address                                                 │                │
                Segment Selector                      ┌────▶├┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┤
               ┌────────────────┐                     │     │                │
               │                ├─────────────────────┘     │                │
               └────────────────┘                           │                │
                                                            │                │
                                                            └────────────────┘

The real-address mode uses a specific implementation of segmented memory in which the linear address space for the
program and the operating system/executive consists of an array of segments of up to 64 KBytes in size each.
The maximum size of the linear address space in real-address mode is 2²° bytes.

## Registers

### General-purpose registers

The 32-bit general-purpose registers EAX, EBX, ECX, EDX, ESI, EDI, EBP, and ESP are provided for holding the
following items:

* Operands for logical and arithmetic operations
* Operands for address calculations
* Memory pointers

#### Table 2. General-purpose registers [ [csv][5] ]

| 31 16 | 15 8 | 7 0 | 16-bit | 32-bit | Special uses (32-bit)                     |
|-------|------|-----|--------|--------|-------------------------------------------|
|       | AH   | AL  | AX     | EAX    | Accumulator for operands and results data |
|       | BH   | BL  | BX     | EBX    | Pointer to data in the DS segment         |
|       | CH   | CL  | CX     | ECX    | Counter for string and loop operations    |
|       | DH   | DL  | DX     | EDX    | I/O pointer                               |

#### Table 3. General-purpose registers [ [csv][6] ]

| 31 0 | 15 0 | 32-bit | Special uses                                                                                                                  |
|------|------|--------|-------------------------------------------------------------------------------------------------------------------------------|
|      | BP   | EBP    | Pointer to data on the stack (in the SS segment)                                                                              |
|      | SI   | ESI    | Pointer to data in the segment pointed to by the DS register; <br>source pointer for string operations                        |
|      | DI   | EDI    | Pointer to data (or destination) in the segment pointed to by <br>the ES register; destination pointer for string operations  |
|      | SP   | ESP    | Stack pointer (in the SS segment)                                                                                             |

### Segment Registers

The segment registers (CS, DS, SS, ES, FS, and GS) hold 16-bit segment selectors. A segment selector is a special
pointer that identifies a segment in memory. To access a particular segment in memory, the segment selector for
that segment must be present in the appropriate segment register.

                                               Linear Address
                                              Space for Program
                                              ┌────────────────┐
                                              │                │
                                              │                │
                                              │   Overlapping  │
    Segment Registers                         │    Segments    │
    ┌────────────────┐                        │    of up to    │
    ├────────────────┤CS ────┐                │    4 GBytes    │
    ├────────────────┤DS ────┤                │  Beginning at  │
    ├────────────────┤SS ────┤                │    Address 0   │
    ├────────────────┤ES ────┤                │                │
    ├────────────────┤FS ────┤                │                │
    └────────────────┘GS ────┴───────────────▶└────────────────┘

When using the flat (unsegmented) memory model, segment registers are loaded with segment
selectors that point to overlapping segments, each of which begins at address 0 of the linear address space.
These overlapping segments then comprise the linear address space for the program. Typically, two
overlapping segments are defined: one for code and another for data and stacks. The CS segment register points
to the code segment and all the other segment registers point to the data and stack segment.

                                         ┌────────────────┐
                                         │  Code Segment  │
                                         │  ┌─────────────┴──┐
                                         │  │  Data Segment  │
                                         │  │  ┌─────────────┴──┐
    Segment Registers                    │  │  │ Stack Segment  │
    ┌────────────────┐            ┌─────▶└──┤  │                │
    ├────────────────┤CS ─────────┘         │  │                │
    ├────────────────┤DS ──────────────────▶└──┤                │
    ├────────────────┤SS ────────────────┐     │                │
    ├────────────────┤ES ─────────────┐  └────▶└────────────────┘
    ├────────────────┤FS ─────────┐   │
    └────────────────┘GS ─────┐   │   │  ┌────────────────┐
                              │   │   │  │  Data Segment  │
                              │   │   │  │  ┌─────────────┴──┐
                              │   │   │  │  │  Data Segment  │
                              │   │   │  │  │  ┌─────────────┴──┐
                              │   │   │  │  │  │ Data Segment   │
                              │   │   └─▶└──┤  │                │
                              │   │         │  │                │
                              │   └────────▶└──┤                │
                              │                │                │
                              └───────────────▶└────────────────┘

When using the segmented memory model, each segment register is ordinarily loaded with a different segment
selector so that each segment register points to a different segment within the linear address space.
At any time, a program can thus access up to six segments in the linear address space. To access a
segment not pointed to by one of the segment registers, a program must first load the segment selector for the
segment to be accessed into a segment register.

Each of the segment registers is associated with one of three types of storage: code, data, or stack.

The register contains the segment selector for the **code segment**, where the instructions being executed are
stored. The processor fetches instructions from the code segment, using a logical address that consists of the
segment selector in the CS register and the contents of the EIP register. The EIP register contains the offset within
the code segment of the next instruction to be executed. The CS register cannot be loaded explicitly by an application
program. Instead, it is loaded implicitly by instructions or internal processor operations that change program
control (such as, procedure calls, interrupt handling, or task switching).

The DS, ES, FS, and GS registers point to four **data segments**. The availability of four data segments permits
efficient and secure access to different types of data structures.

The SS register contains the segment selector for the stack **segment**, where the procedure stack is stored for the
program, task, or handler currently being executed. All stack operations use the SS register to find the stack
segment. Unlike the CS register, the SS register can be loaded explicitly, which permits application programs to set
up multiple stacks and switch among them.

### EFLAGS Register



#Instructions

#Appendix of Tables

* [Table 1. Bit and Byte Order](#table-1-bit-and-byte-order--csv-) 
* [Table 2. General-purpose registers](#table-2-general-purpose-registers--csv-)
* [Table 3. General-purpose registers](#table-3-general-purpose-registers--csv-)

#References

1. [Intel® 64 and IA-32 Architectures Software Developer’s Manual][1] (PDF)
2. [The Real, Protected, Long mode assembly tutorial for PCs][4]

[1]: http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-manual-325462.pdf "Intel® 64 and IA-32 Architectures Software Developer’s Manual"
[2]: http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-optimization-manual.pdf "Intel® 64 and IA-32 Architectures Optimization Reference Manual"
[3]: tables/bit_and_byte_order.csv "Bit and Byte Order download"
[4]: http://www.codeproject.com/Articles/45788/The-Real-Protected-Long-mode-assembly-tutorial-for "The Real, Protected, Long mode assembly tutorial for PCs"
[5]: tables/gen_purp_registers_part_1.csv "General-purpose registers"
[6]: tables/gen_purp_registers_part_2.csv "General-purpose registers"
