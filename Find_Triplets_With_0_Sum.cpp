//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {  
        sort(arr, arr+n);
        int j, k;
        for(int i = 0; i < n; i++)
        {
            j = i+1;
            k = n-1;
            while(j < k)
            {
                if(arr[i] + arr[k] + arr[j] == 0)
                    return true;
                else if(arr[i] + arr[j] + arr[k] > 0)
                    k--;
                else j++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends


// Leet Code Similiar Question :- 3 sum

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++) {
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             int j = i + 1;
//             int k = n - 1;
//             while (j < k) {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if (sum < 0)
//                     j++;
//                 else if (sum > 0)
//                     k--;
//                 else {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     ans.push_back(temp);
//                     j++;
//                     k--;
//                     while (j < k && nums[j] == nums[j - 1])
//                         j++;
//                     while (j < k && nums[k] == nums[k + 1])
//                         k--;
//                 }
//             }
//         }
//         return ans;
//     }
// };