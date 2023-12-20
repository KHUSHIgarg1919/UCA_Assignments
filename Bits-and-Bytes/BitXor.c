//Bit XOR
/*
/*  bitXor - x ^ y using only ~ and &
/* Example bitXor(4, 5) = 1
/* Legal ops:  ~ &  
/* Max ops: 14
*/

#include<stdio.h>
int bitXor (int x, int y) {
    return ~(~(x&(~y)) & ~((~x)&y));
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int ans = bitXor(x,y);
    printf("%d",ans);
}