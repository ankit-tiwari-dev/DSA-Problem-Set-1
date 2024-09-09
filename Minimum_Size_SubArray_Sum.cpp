#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, int arr[], int n)
    {
        int minLen = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            while (sum >= target)
            {
                minLen = min(minLen, (i - j + 1));
                sum -= arr[j];
                j++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minSubArrayLen(target, arr, n) << endl;
    }

    return 0;
}