#include <stdio.h>
#define MACRO int*

typedef int* pointer;

int main()
{
    pointer one,two,three;
    printf("All are pointers: %zu %zu %zu\n",sizeof(one),sizeof(two),sizeof(three));
    MACRO num1,num2,num3;
    num1 = (MACRO)0x1235;
    printf("Only first one is a pointer: %zu %zu %zu\n",sizeof(num1),sizeof(num2),sizeof(num3));
    return 0;
}
