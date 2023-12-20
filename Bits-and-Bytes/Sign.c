//Sign
/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/

#include<stdio.h>
int sign(int x) {
    int result = (x>>31) | (!!x);
    if(result>0) return 1;
    else if(result<0) return -1;
    else return 0;
}
int main(){
    int x;
    scanf("%d",&x);
    int ans = sign(x);
    printf("%d",ans);
}