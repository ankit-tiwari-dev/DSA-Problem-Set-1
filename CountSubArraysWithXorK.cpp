#include <iostream>
#include <vector>
#include <map>
using namespace std;
int CountSubArrayWithXorK(vector<int> arr, int n, int k)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr;
    int n, k;
    cout << "Enter Size of Array : ";
    cin >> n;
    cout << "Enter Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter A[" << i << "] : ";
        cin >> arr[i];
    }
    cout << "Enter Target : ";
    cin >> k;

    int ans = CountSubArrayWithXorK(arr, n, k);

    return 0;
}