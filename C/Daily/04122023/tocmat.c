#include <stdio.h>
#include <string.h>

char alpha[30] = "abcdefghstuvwxyzijklmnopqr";

int get_val(char c)
{
	for(int i=0;i<26;i++)
	{
		if(c == alpha[i])
			return i;
	}
}

void sort_asc(char *str,int *i,int limit)
{
	int temp = *i;
	for(*i;*i < limit - 1;(*i)++)
	{
		for(int j = temp ;j < limit - 1 ; j++)
		{
			if(get_val(str[j]) > get_val(str[j+1]))
			{
				str[j] = str[j] ^ str[j+1];
				str[j+1] = str[j] ^ str[j+1];
				str[j] = str[j] ^ str[j+1];
			}
		}
	}
}

void sort_des(char *str,int *i,int limit)
{
	int temp = *i;
	for(*i;*i < limit - 1;(*i)++)
	{
		for(int j = temp ;j < limit - 1 ; j++)
		{
			if(get_val(str[j]) < get_val(str[j+1]))
			{
				str[j] = str[j] ^ str[j+1];
				str[j+1] = str[j] ^ str[j+1];
				str[j] = str[j] ^ str[j+1];
			}
		}
	}
}



int main()
{
	int k;
	char str[200];
	printf("Enter a string and k\n");
	scanf("%s",str);
	scanf("%d",&k);
	int i=0,limit = k;
	for(;i<strlen(str);)
	{
		sort_asc(str,&i,limit);
		i = limit;
		limit = limit + k;
		sort_des(str,&i,limit);
		i = limit;
		limit = limit + k;
	}
	printf("%s\n",str);
}



