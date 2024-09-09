#include <iostream>
#include <vector>
using namespace std;

// Time Complexity :- O(log n)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] - (mid + 1) < k)
            {
                low = mid + 1;
            }
            else  high = mid -1;
        }
        return low + k;
    }
};
// Time Complexity :- O(n);
// Easy Solution 

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int j = 0;
        int maxi = arr[arr.size() - 1];
        int count = 0;
        int n = 0;
        for(int i = 1; i <= maxi; i++)
        {
            if(i == arr[j]){
                j++;
            }
            else{
                count++;
                n = i;
            }
            if(count == k)  return n;  
        }
        if(count == 0)  return maxi+k; 
        return (maxi - count) + k;
    }
};