//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int lower_bound(int arr[], int n, int x)
    {
        int ans = -1;
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] >= x)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    
    int upper_bound(int arr[], int n, int x)
    {
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] <= x)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
    vector<int> find(int arr[], int n , int x )
    {
        int i = lower_bound(arr, n, x);
        if (i == -1 || (i < n && arr[i] != x)) {  
            return {-1, -1};  
        }  
        int j = upper_bound(arr, n, x)-1;  
        return {i, j};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends