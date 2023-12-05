#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter three numbers\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("a is %d\nb is %d\nc is %d\n",a,b,c);
	(a>b)?(a>c)?printf("a %d is greater\n",a):printf("c %d is greater\n",c):(b>c)?printf("b %d is greater\n",b):printf("c %d is greater\n",c);
}
