/*
Problem statement.
You are given a string str consisting of lower case English alphabets only and an integer K. You have to arrange the k alphabets in ascending order and next k alphabets in descending order and so on as per the following pattern. 
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
Sample input :
Tomcat
2
Output:
tomcat
Sample 2:
input 
aiu
3 
output: 
aui
*/


#include <stdio.h>

char alpha[30] = "abcdefghstuvwxyzijklmnopqr";

int get_val(char var)
{
    for(int i=0;i<=26;i++)
    {
        if(var == alpha[i])
        {
            return i;
        }
    }
}

int len(char *ptr)
{
    int count = 0;
    while(*ptr)
    {
        count++;
        ptr++;
    }
    return count;
}


int main()
{
    int k;
    char str[200];
    printf("Enter the k value and a string\n");
    scanf("%d %s",&k,str);
    int l = len(str);
    printf("%d\n",l);
    printf("%s\n",str);
    int limit = k;

    for(int i=0;i<l;)
    {
        for(;i<limit-1;i++)
        {
            if(get_val(str[i]) > get_val(str[i+1]))
            {
                str[i] = str[i] ^ str[i+1];
                str[i+1] = str[i] ^ str[i+1];
                str[i] = str[i] ^ str[i+1];
            }
        }
    
        for(i=limit;i<limit+k-1;i++)
        {
            if(get_val(str[i]) < get_val(str[i+1]))
            {
                str[i] = str[i] ^ str[i+1];
                str[i+1] = str[i] ^ str[i+1];
                str[i] = str[i] ^ str[i+1];
            }
        }
        i = limit+ k;
        limit +=k*2;
    }
    printf("%s\n",str);
    return 0;
}
