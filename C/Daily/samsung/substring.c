/*
Problem statement:
You are given two strings S and T. You don’t want T to occur in S as a subsequence. 
For this you can reshuffle the characters of the string S in any manner you like. After you do so, you need to tell
If there is a string S` which does not have T as a subsequence. If you can do so, print “YES” else print “NO”

Note:
•	S` is the string obtained after reshuffling the string S.
•	S` can be equal to S too.

Input Format:
The Input is in the following format:
•	The first line contains a single integer 2*T, where T denotes the number of test cases. 
•	Then, 2*T lines follow.

Output Format:
Print “YES” or “NO” for each test case, based on your answer, in a separate line.

Constraints:
•	1 <=T<=100
•	1<=length of any string <= 100

Example:
Input:
2
abcd
abcd

Output:
YES

Explanation:
Reshuffle S, such that S` = abdc. Now, no subsequence in S` equals T, hence the answer is YES.

Sample input 2:
2
aaaa
aaaa

Ouput:
NO 

Sample input 3 :
4
asas
assa
vvv
vvv

output:
YES
NO
*/

#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int res = 0;

// Function to swap characters at positions i and j in a string
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void isSubsequence(char *str, char *T)
{
    char str1[10] = "\0";
        int num = 0, flag = 1;
        for(int i = 0;str[i] != '\0';i++)
        {
            for(int j = 0;j < num;j++)
            {
                if(str[i] == str1[j])
                {
                    flag = 0;
                }
            }
            if(flag == 1)
            {
                for(int j = 0;T[j] != '\0';j++)
                {
                    if(str[i] == T[j])
                    {
                        str1[num++] = str[i];
                    }
                }
            }
        }
        str1[num] = '\0';
        if(strcmp(str1, T) == 0)
        {
            res = 1;
        }
}


// Function to generate permutations of a string
void generatePermutations(char* str, char *T, int start, int end) 
{
    if (start == end && (strcmp(str, T) != 0)) 
    {
        isSubsequence(str, T);
        return;
    }

    for (int i = start; i <= end; i++) 
    {
        // Swap the current character with the character at position 'i'
        swap(&str[start], &str[i]);

        // Recursively generate permutations for the remaining characters
        generatePermutations(str, T, start + 1, end);
    }
}

int main() 
{
    int t;
    scanf("%d",&t);
    char S[100],T[100];
    for(int i=0; i<(t/2); i++)
    {
        scanf("%s",S);
        scanf("%s",T);

        int freq_str[26] = {0};

        for(int i = 0;S[i] != '\0';i++)
        {
            freq_str[S[i] - 'a']++;
        }

        int flag = 0;
        if(strcmp(S, T) == 0)
        {
            for(int i = 0;i < 26;i++)
            {
                if(freq_str[i] == strlen(S))
                {
                    flag = 1;
                    res = 1;
                    break;
                }
            }
        }

        if(flag == 0)
        {
            generatePermutations(S, T, 0, strlen(S) - 1);
        }
        if(res == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
