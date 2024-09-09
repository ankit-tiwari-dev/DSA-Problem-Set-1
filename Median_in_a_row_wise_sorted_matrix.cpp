//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int blackbox(vector<vector<int>> &matrix, int x, int n, int m)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += upper_bound(matrix[i], x, m);
        }
        return cnt;
    }
    int upper_bound(vector<int>arr, int x, int m)
    {
        int low = 0;
        int high = m - 1;
        int ans = m;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = INT_MAX;
        int high = INT_MIN;
        int req  = (R*C) / 2;
        for(int i = 0; i < matrix.size(); i++)
        {
            if(low > matrix[i][0]) low = matrix[i][0];
            if(high < matrix[i][C-1]) high = matrix[i][C-1];
        }
        
        while(low <= high)
        {
            int mid = (low + high)/ 2;
            int SmallerEquals = blackbox(matrix,mid, R, C);
            if(SmallerEquals <= req)
            {
                low = mid +1;
            }
            else 
            {
                high = mid -1;
            }
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends