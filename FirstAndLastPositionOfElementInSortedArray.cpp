#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) { 
        vector<int> ans;
        int low = 0;
        int high = arr.size() - 1;
        int first = -1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } 
            else
            {
                if(arr[mid] == target)  first = mid;
                high = mid - 1;
            }
        }
        
        low = 0;
        high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target) {
                if(arr[mid] == target) last = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};