#include <stdio.h>

void fibonacci(int num,int a,int b, int c)
{
    if(a >= num+1)
    {
        printf("This is entered\n");
        return;
    }
    else
    {
        printf("%d ",a);
        a = b;
        b = c;
        c = a+b;
        fibonacci(num,a,b,c);
    }
    
}

int main()
{
    int num = 0;
    int a=0,b=1,c=a+b;
    printf("Enter a number\n");
    scanf("%d",&num);
    printf("Fibonacci of %d is:",num);
    fibonacci(num,a,b,c);
    printf("\n");
}
