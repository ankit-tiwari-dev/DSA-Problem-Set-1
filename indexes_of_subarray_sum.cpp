// Givrn code is 1 based indexing
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        
        vector<int> ans;
        long long sum = 0;
        int left = 0;
        if(s == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i] == 0) return {i+1, i+1};
            }
        }
        
        for(int right = 0; right < n; right++)
        {
            sum += arr[right];
            while(sum > s && left <= right)
            {
                sum -= arr[left];
                left++;
            }
            if(s == sum && sum != 0)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends