//Bit And
/*
/* bitAnd - x & y using only ~ and |
/* Example bitAnd(6, 5) = 4
/* Legal ops:  ~ |  
/* Max ops: 8
*/

#include <stdio.h>
int bitAnd (int x, int y) {
    return ~((~x)|(~y));
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int ans = bitAnd(x,y);
    printf("%d",ans);
}