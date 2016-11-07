/**
 *
 *  Simple example with printf and loop
 *
 * Section main from objdump -d loop_with_pritf_gcc
 *
 *  080483fb <main>:
 *  80483fb: 8d 4c 24 04             lea    0x4(%esp),%ecx
 *  80483ff: 83 e4 f0                and    $0xfffffff0,%esp
 *  8048402: ff 71 fc                pushl  -0x4(%ecx)
 *  8048405: 55                      push   %ebp
 *  8048406: 89 e5                   mov    %esp,%ebp
 *  8048408: 51                      push   %ecx
 *  8048409: 83 ec 14                sub    $0x14,%esp
 *  804840c: c7 45 f4 00 00 00 00    movl   $0x0,-0xc(%ebp)
 *  8048413: eb 17                   jmp    804842c <main+0x31>
 *  8048415: 83 ec 08                sub    $0x8,%esp
 *  8048418: ff 75 f4                pushl  -0xc(%ebp)
 *  804841b: 68 d0 84 04 08          push   $0x80484d0
 *  8048420: e8 ab fe ff ff          call   80482d0 <printf@plt>
 *  8048425: 83 c4 10                add    $0x10,%esp
 *  8048428: 83 45 f4 01             addl   $0x1,-0xc(%ebp)
 *  804842c: 83 7d f4 09             cmpl   $0x9,-0xc(%ebp)
 *  8048430: 7e e3                   jle    8048415 <main+0x1a>
 *  8048432: b8 00 00 00 00          mov    $0x0,%eax
 *  8048437: 8b 4d fc                mov    -0x4(%ebp),%ecx
 *  804843a: c9                      leave
 *  804843b: 8d 61 fc                lea    -0x4(%ecx),%esp
 *  804843e: c3                      ret
 *  804843f: 90                      nop
 *
 */

#include <stdio.h>

int main(){
    int i;
    for (i = 0; i < 10; i++) {
        printf("Iteration %d\n", i);
    }
    return 0;
}
