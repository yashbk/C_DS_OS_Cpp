#include <stdio.h>

int main()
{
	char str[10];
	char repeated[10];
	printf("Enter a string\n");
	scanf("%s",str);
	int i=0,len=0,j=0,flag = 0;
	int rep = 0;
	while(str[i] != '\0')
	{
		len++;
		i++;
	}

	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if(str[i] == str[j] && i!=j)
			{
				printf("%c\n",str[i]);
				break;
			}
		}
	}
}
