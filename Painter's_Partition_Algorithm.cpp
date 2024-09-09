//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isValid(int arr[], long long int unit, int n, int m)
    {
        int cntBoard = 0;
        int count = 1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] + cntBoard <= unit)
            {
                cntBoard += arr[i];
            }
            else
            {
                count++;
                cntBoard = arr[i];
            }
        }
        return count <= m;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long int maxi = INT_MIN;
        long long int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(maxi < arr[i])   maxi = arr[i];
            sum += arr[i];
        }
        
        long long int low = maxi;
        long long int high = sum;
        long long int ans = 0;
        while(low <= high)
        {
            long long int mid = (low + high) / 2;
            if(isValid(arr, mid, n, k))  
            {
                ans = mid;
                high = mid -1;
            }
            else low = mid + 1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends