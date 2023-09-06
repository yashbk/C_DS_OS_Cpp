#include <stdio.h>

int main()
{
	char str[10];
	printf("Enter the string:\n");
	scanf("%s",str);
	int len=0,i=0,out = 0;
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	printf("len is %d\n",len);
	while(i < len)
	{
		if(str[i] >= 48 && str[i] <= 57)
		{
			out = out * 10 + (int)str[i] - 48;
		}
		i++;
	}
	printf("%d\n",out);
}


