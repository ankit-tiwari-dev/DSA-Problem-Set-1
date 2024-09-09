#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& A, int low, int mid, int high) {
        vector<int> ans;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (A[left] <= A[right]) {
                ans.push_back(A[left]);
                left++;
            } else {
                ans.push_back(A[right]);
                right++;
            }
        }
        while (left <= mid) {
            ans.push_back(A[left]);
            left++;
        }
        while (right <= high) {
            ans.push_back(A[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            A[i] = ans[i - low];
        }
    }

    int countPairs(vector<int>& A, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && A[i] > (long)2 * A[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& A, int low, int high) {
        int cnt = 0;
        int mid;
        if (low >= high)
            return 0;
        mid = (low + high) / 2;
        cnt += mergeSort(A, low, mid);
        cnt += mergeSort(A, mid + 1, high);
        cnt += countPairs(A, low, mid, high);
        merge(A, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};