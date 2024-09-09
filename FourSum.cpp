#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> FourSum(int arr[], int n, int target)
{
    vector<vector<int>> ans;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int l = j + 1;
            int k = n - 1;

            while (l < k)
            {
                int fourSum = arr[i] + arr[j] + arr[k] + arr[l];
                if (fourSum > target)
                    k--;
                else if (fourSum < target)
                    l++;
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[l], arr[k]};
                    k--;
                    l++;
                    ans.push_back(temp);
                    while (l < k && arr[k] == arr[k + 1])
                        k--;
                    while (l < k && arr[l] == arr[l - 1])
                        l++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the Size of the Array : ";
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    cout << "Enter Array : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "] : ";
        cin >> arr[i];
    }
    cout<<"Enter Target value : ";
    int k;
    cin >>k;
    
    vector<vector<int>> temp = FourSum(arr, n, k);
    cout << "Quater adding up to " << k << " are:" << endl;
    for (const auto &triplet : temp)
    {
        cout << "{";
        for (const auto &num : triplet)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    free(arr);
    return 0;
}