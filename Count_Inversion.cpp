#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long count = 0;
    void merge(long long A[], long long low, long long mid, long long high)
    {
        vector<long long> ans;

        long long left = low;
        long long right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (A[left] <= A[right])
            {
                ans.push_back(A[left]);
                left++;
            }
            else
            {
                ans.push_back(A[right]);
                count += (mid - left + 1);
                right++;
            }
        }
        while (left <= mid)
        {
            ans.push_back(A[left]);
            left++;
        }
        while (right <= high)
        {
            ans.push_back(A[right]);
            right++;
        }
        for (long long i = low; i <= high; i++)
        {
            A[i] = ans[i - low];
        }
    }

    void mergeSort(long long A[], long long low, long long high)
    {
        long long mid;
        if (low >= high)
            return;
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
    long long int inversionCount(long long arr[], int n)
    {
        mergeSort(arr, 0, n - 1);
        return count;
    }
};