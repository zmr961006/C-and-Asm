.section .text
.globl _start
_start:
    movl $10,%ecx
    movl $12,%edx
    addl %edx,%ecx
    movl %ecx,%ebx
    
    movl $1,%eax
    int  $0x80


