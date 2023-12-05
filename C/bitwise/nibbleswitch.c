
#include <stdio.h>

void print(int num)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d ",num >> i & 0x01);
    }
    printf("\n");
}

int main() {
    char num = 0xF0;
    print(num);
    num = ((num & 0xF0) >> 4) | ((num & 0x0F) << 4);
    print(num);

    return 0;
}