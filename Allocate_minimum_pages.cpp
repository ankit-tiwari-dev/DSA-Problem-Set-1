//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    int countStudent(int arr[], int pages, int n)
    {
        int cntPages = arr[0];
        int stu = 1;
        for(int i = 1; i < n; i++)
        {
            if(cntPages + arr[i] <= pages)
            {
                cntPages += arr[i];
            }
            else
            {
                stu++;
                cntPages = arr[i];
            }
        }
        return stu;
    }
    long long findPages(int n, int arr[], int m) {
        if(m > n) return -1;
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(maxi < arr[i])    maxi = arr[i];
        }
        int low = maxi;
        int high = sum;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int cntStu = countStudent(arr, mid, n);
            if(cntStu <= m)
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends