#include <stdio.h>
#define SIZEOF(num) (char*)&num - (char*)(&num-1)

void my_sizeof(int num)
{
    int *ptr = &num;
    printf("%ld\n",(char*)&num - (char*)--ptr);
}

int main()
{
    int num = 4;
    my_sizeof(num);
    printf("%ld\n",SIZEOF(num));
}