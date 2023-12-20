//Get Byte
/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
* Legal ops: ! ~ & ^| + << >>
  Max ops: 6
*/

#include<stdio.h>
int getByte(int x, int n) {
    return (x>>(n<<3)) & 0xFF;            //0xFF means 255
}
int main(){
    int x = 0x12345678;
    int n = 1;
    int ans = getByte(x,n);
    printf("0x%X",ans);                 //%X is used to convert into hexadecimal
}