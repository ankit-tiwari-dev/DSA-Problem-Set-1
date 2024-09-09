#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int> &nums, int x, int threshold)
    {
        int sum = 0;        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += ceil((float)nums[i]/x);
        }
        if(sum <= threshold) return true;
        return false;
    }
    int maxi(vector<int> &nums)
    {
        int maxx = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(maxx < nums[i])
                maxx = nums[i];
        }
        return maxx;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = 1;
        int low = 1;
        int high = maxi(nums);
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(possible(nums, mid, threshold))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};