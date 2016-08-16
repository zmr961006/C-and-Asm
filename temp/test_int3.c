/*************************************************************************
	> File Name: test_int3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月15日 星期一 10时18分44秒
 ************************************************************************/

#include<stdio.h>



int main(){

    while(1){
        printf("hello world\n");
        __asm__ __volatile__("int3");
    }



}
