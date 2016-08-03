##第二章 初识汇编

首先，看着这样的一个C程序。

```
#include<stdio.h>

int main(){
    
    int a = 0;
    int b = 10;

    return ( a + b );

}
```

很简单，返回一个A+B的和。现在我们使用汇编来编写一遍这个程序。直接使用64位汇编

```
.section .text
.globl _start
_start:
    movq $10,%rcx
    movq $12,%rdx
    addq %rdx,%rcx
    ;movq %rcx,%rbx
    
    movq %rbx,%rax
    int  $0x80


编译完成后：echo $? 查看函数返回值

```
这里值得注意的地方在我们自己手写汇编时，需要调用0x80号中断，所以我们需要将返回值保存在rbx 寄存器而不是屏时看见的保存在eax中。


下来我们考察一个例子，彻底观察下函数调用。

```
#include<stdio.h>


int fun(int a,int b){

    int c = 0;
    c = a + b;
    return c;

}


int main(){
    
    int x = 10;
    int y = 10;
    int z = fun(x,y);

    return z;
    
}

```

这个是我们使用GCC -S 得到的汇编代码。

```
	.file	"testcc.c"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	pushq	%rbp                     /*保存堆栈基址指针*/
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp               /*必须由一个指针保存rsp，(隐式SP — —) */
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	$0, -4(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret                             /*返回上一级函数（隐式SP + + ）*/
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:                                 /* start函数从这里开始 */
.LFB1:
	.cfi_startproc
	pushq	%rbp                      /*调用范式，保存数据堆栈指针*/
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                /* 设置堆栈指针*/
	.cfi_def_cfa_register 6
	subq	$16, %rsp                 /* 预留栈空间 */
	movl	$10, -4(%rbp)             /*参数入栈*/
	movl	$10, -8(%rbp)        
	movl	$0, -12(%rbp)
	movl	-8(%rbp), %edx 
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	fun                      /*调用函数*/
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.9.2 20150212 (Red Hat 4.9.2-6)"
	.section	.note.GNU-stack,"",@progbits
```


  函数返回地址
  局部变量
  。
  。
  。
  参数入栈
  




