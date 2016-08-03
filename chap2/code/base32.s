.section .text
.globl _start
_start:
    movq $10,%rcx
    movq $12,%rdx
    addq %rdx,%rcx
    ;movq %rcx,%rbx
    
    movq %rbx,%rax
    int  $0x80


