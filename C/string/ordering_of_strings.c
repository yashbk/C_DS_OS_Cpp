/*
You will be given N number of strings. You have to find the lexicographically smallest string and the lexicographically largest string among these strings.

Example 1:

Input:
N = 3
strings = a , ab , abc
Output: a abc
Explanation: Lexicographically smallest is
"a" and lexicographically largest is
"abc".
 

Example 2:

Input:
N = 2
strings = abc , abc
Output: abc abc
Explanation: Lexicographically smallest is
"abc" and lexicographically largest is
"abc"
 

Your Task:  
Expected Time Complexity: O(N* max of all string length ).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= N , length of each string <= 103
*/

#include <stdio.h>
#include <string.h>

void low_high(int N,char str[N][103])
{
    int arr[N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j< strlen(str[i]);j++)
        {
            arr[i] += str[i][j];
        }
    }

    int low = 0x7fffffff;
    int high = 0;
    int low_index = 0;
    int high_index = 0;
    for(int i=0;i<N;i++)
    {
        if(low > arr[i])
        {
            low = arr[i];
            low_index = i;
        }
        if(high < arr[i])
        {
            high = arr[i];
            high_index = i;
        }
    }
    
    printf("High is :%s\nLow is :%s\n%d %d\n",str[high_index],str[low_index],high_index,low_index);
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    char str[N][103];
    for(int i=0;i<N;i++)
    {
        printf("Enter the string %d:\n",i);
        scanf("%s",str[i]);
    }
    low_high(N,str);

}