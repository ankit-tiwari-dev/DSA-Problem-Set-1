//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int rem = 0;
        int maxLen = 0;
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            if(sum == K)
                maxLen = max(maxLen, i+1);
            rem = sum - K;
            if(prefixSum.find(rem) != prefixSum.end())
                maxLen = max(i - prefixSum[rem], maxLen);
            if(prefixSum.find(sum) == prefixSum.end()) 
                prefixSum[sum] = i;
        }
        return maxLen;
    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends