/*
You are given a string str consisting of lower case english alphabets only and an integer K. You have to arrange the k alphabets in ascending order and next k alphabets in descending order and so on as per the following pattern. 
“abcdefghstuvwxyzijklmnopqr”
Note:
The pattern that needs to be followed to arrange the elements in ascending and descending order as “abcdefghstuvwxyzijklmnopqr”

Input format:
The input consists of a two lines:
	The first line contains a string str.
	The second line contains an integer k.
The input will be read from the STDIN by the candidate.

Output Format:
Print the resultant string.
Constraints:
1 <= length of string <= 200
1 <=k <=6

Sample input:
tomcat
2

Output:
tomcat

*/

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



