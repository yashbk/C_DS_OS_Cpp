/*
Given three inputs A B and N.
You can do any one of the following operations.
Increment A by B 
Increment B by A

Return the min number of increments to make A or B greater than N.
Example:
4 4 16
output:
3

Exmaple 2:
1 2 3
Ouptput:
2

*/

#include <stdio.h>

int main()
{
    int A,B,N;
    printf("Enter A B and N\n");
    scanf("%d%d%d",&A,&B,&N);

    for(int i=0;;i++)
    {
        if(((A + (B*i)) >N) || ((B + (A*i)) >N))
        {
		if(A == B)
		{
			printf("%d\n",i-1);
			return 0;
		}
		else
		{
            		printf("%d\n",i);
            		return 0;
		}
        }
    }

}
