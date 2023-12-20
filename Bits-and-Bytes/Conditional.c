//Conditional
/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/

#include<stdio.h>
#include<assert.h>
int conditional(int x, int y, int z) {
    int mask = !x-1;
    return (mask&y) | (~mask&z);
}
int main(){
    assert(conditional(2,4,5)==4);
    assert(conditional(0,4,5)==5);
}