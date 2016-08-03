/*************************************************************************
	> File Name: testcc.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月03日 星期三 14时31分34秒
 ************************************************************************/

#include<stdio.h>


int fun(int a,int b){

    int c = 0;
    c = a + b;
    return c;

}


int main(){
    
    int x = 10;
    int y = 10;
    int z = 0;
    z = fun(x,y);
    return z;
}
