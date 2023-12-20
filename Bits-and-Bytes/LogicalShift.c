//Logical Shift
/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
*  examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*  Max ops: 20
*/

#include<stdio.h>
#include<assert.h>
int logicalShift(int x, int n) {
    return (x>>n)&(~(~0<<(32+(~n+1))));
}
int main(){
    assert(logicalShift(0x87654321, 4)==0x8765432);
}