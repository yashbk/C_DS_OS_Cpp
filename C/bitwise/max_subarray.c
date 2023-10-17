#include<bits/stdc++.h>
using namespace std;

int maxsubarray(int *arr, int size)
{
    int maxend = arr[0];
    int maxtillnow = arr[0];
    for(int i=1;i<size;i++)
    {
        maxend = (maxend + arr[i]) > arr[i]?(maxend + arr[i]):arr[i];

        maxtillnow = (maxend > maxtillnow) ? maxend:maxtillnow;
    }
    return maxtillnow;

}

int main() {
    int N = 0;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
	int result = maxsubarray(arr,N);
    cout << result;
}