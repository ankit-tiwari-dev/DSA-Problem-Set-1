#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int LongestSubArrayZeroSum(int arr[], int n)
{
    map<int, int> prefix;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if(prefix.find(sum) != prefix.end())
                maxi = max(maxi, i - prefix[sum]);
            else
                prefix[sum] = i;
        }
    }
    return maxi;      
}
int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int count = LongestSubArrayZeroSum(arr, n);
    cout<<count;
    return 0;
}