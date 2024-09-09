//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        int index = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid])
            {
                if(nums[low] < mini)
                {
                    mini = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else
            {
                if(nums[mid] < mini)
                {
                    mini = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends