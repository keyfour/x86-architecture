
    ██╗  ██╗ █████╗  ██████╗        █████╗ ██████╗  ██████╗██╗  ██╗
    ╚██╗██╔╝██╔══██╗██╔════╝       ██╔══██╗██╔══██╗██╔════╝██║  ██║
     ╚███╔╝ ╚█████╔╝███████╗ █████╗███████║██████╔╝██║     ███████║
     ██╔██╗ ██╔══██╗██╔═══██╗╚════╝██╔══██║██╔══██╗██║     ██╔══██║
    ██╔╝ ██╗╚█████╔╝╚██████╔╝      ██║  ██║██║  ██║╚██████╗██║  ██║
    ╚═╝  ╚═╝ ╚════╝  ╚═════╝       ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝

* [Basic Architecture](#basic-architecture)
    * [Bit and Byte Order](#bit-and-byte-order)
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



## Registers



#Instructions

#Appendix of Tables

* [Table 1.](#table-1-bit-and-byte-order--csv-) Bit and Byte Order 

#References

1. Intel® 64 and IA-32 Architectures Software Developer’s Manual [[pdf][1]]

[1]: http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-manual-325462.pdf "Intel® 64 and IA-32 Architectures Software Developer’s Manual"
[2]: http://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-optimization-manual.pdf "Intel® 64 and IA-32 Architectures Optimization Reference Manual"
[3]: tables/bit_and_byte_order.csv "Bit and Byte Order download"
