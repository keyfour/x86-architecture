/**
 *
 * Simple example with printf and function_calls
 *
 * Sections: main and called functions
 * from objdump -d loop_with_pritf_gcc
 *
 * 080483fb <function_void>:
 * 80483fb:	55                   	push   %ebp
 * 80483fc:	89 e5                	mov    %esp,%ebp
 * 80483fe:	83 ec 10             	sub    $0x10,%esp
 * 8048401:	8b 55 fc             	mov    -0x4(%ebp),%edx
 * 8048404:	8b 45 f8             	mov    -0x8(%ebp),%eax
 * 8048407:	01 d0                	add    %edx,%eax
 * 8048409:	99                   	cltd
 * 804840a:	f7 7d fc             	idivl  -0x4(%ebp)
 * 804840d:	0f af 45 f8          	imul   -0x8(%ebp),%eax
 * 8048411:	89 45 f4             	mov    %eax,-0xc(%ebp)
 * 8048414:	c9                   	leave
 * 8048415:	c3                   	ret
 *
 * 08048416 <function_int>:
 * 8048416:	55                   	push   %ebp
 * 8048417:	89 e5                	mov    %esp,%ebp
 * 8048419:	83 ec 10             	sub    $0x10,%esp
 * 804841c:	8b 55 08             	mov    0x8(%ebp),%edx
 * 804841f:	8b 45 0c             	mov    0xc(%ebp),%eax
 * 8048422:	01 d0                	add    %edx,%eax
 * 8048424:	99                   	cltd
 * 8048425:	f7 7d 08             	idivl  0x8(%ebp)
 * 8048428:	0f af 45 0c          	imul   0xc(%ebp),%eax
 * 804842c:	89 45 fc             	mov    %eax,-0x4(%ebp)
 * 804842f:	8b 45 fc             	mov    -0x4(%ebp),%eax
 * 8048432:	c9                   	leave
 * 8048433:	c3                   	ret
 *
 * 08048434 <main>:
 * 8048434:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 * 8048438:	83 e4 f0             	and    $0xfffffff0,%esp
 * 804843b:	ff 71 fc             	pushl  -0x4(%ecx)
 * 804843e:	55                   	push   %ebp
 * 804843f:	89 e5                	mov    %esp,%ebp
 * 8048441:	51                   	push   %ecx
 * 8048442:	83 ec 14             	sub    $0x14,%esp
 * 8048445:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 * 804844c:	eb 28                	jmp    8048476 <main+0x42>
 * 804844e:	ff 75 f4             	pushl  -0xc(%ebp)
 * 8048451:	ff 75 f4             	pushl  -0xc(%ebp)
 * 8048454:	e8 bd ff ff ff       	call   8048416 <function_int>
 * 8048459:	83 c4 08             	add    $0x8,%esp
 * 804845c:	83 ec 08             	sub    $0x8,%esp
 * 804845f:	50                   	push   %eax
 * 8048460:	68 20 85 04 08       	push   $0x8048520
 * 8048465:	e8 66 fe ff ff       	call   80482d0 <printf@plt>
 * 804846a:	83 c4 10             	add    $0x10,%esp
 * 804846d:	e8 89 ff ff ff       	call   80483fb <function_void>
 * 8048472:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 * 8048476:	83 7d f4 0a          	cmpl   $0xa,-0xc(%ebp)
 * 804847a:	7e d2                	jle    804844e <main+0x1a>
 * 804847c:	b8 00 00 00 00       	mov    $0x0,%eax
 * 8048481:	8b 4d fc             	mov    -0x4(%ebp),%ecx
 * 8048484:	c9                   	leave
 * 8048485:	8d 61 fc             	lea    -0x4(%ecx),%esp
 * 8048488:	c3                   	ret
 * 8048489:	66 90                	xchg   %ax,%ax
 * 804848b:	66 90                	xchg   %ax,%ax
 * 804848d:	66 90                	xchg   %ax,%ax
 * 804848f:	90                   	nop
 *
 */

#include <stdio.h>

void function_void(){
    int a,b,c;
    c = (a + b)/a*b;
}

int function_int(int a, int b) {
    int c;
    c = (a + b)/a*b;
    return c;
}

int main(){
    int i;
    for (i = 1; i < 11; i++) {
        printf("Iteration %d\n", function_int(i,i));
        function_void();
    }
    return 0;
}
