//print the first non-repeated character from a string.
#include <stdio.h>

int main()
{
	char str[10];
	printf("Enter the string:\n" );
	scanf("%s",str);
	int i=0,j=0,len=0,flag = 0;
	while(str[i] != '\0')
	{
		i++;
		len++;
	}

	for(i=0;i<len;i++)
	{
		flag = 0;
		for(j=i;j<len;j++)
		{
			if(str[i] == str[j])
			{
				flag = 1;
			}
		}
		if(!flag)
			printf("non repeated char is %c\n",str[i]);
	}
}

