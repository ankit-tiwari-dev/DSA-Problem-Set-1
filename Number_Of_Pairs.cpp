//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binarySearch(vector<int>&arr, int n, int element)
    {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > element)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        
        int zero = 0, one = 0, two = 0, three = 0, four = 0;
        long long ans = 0;
        int ind = 0;
        for(int i = 0; i < brr.size(); i++)
        {
            if(brr[i] == 0) zero++;
            else if(brr[i] == 1) one++;
            else if(brr[i] == 2) two++;
            else if(brr[i] == 3) three++;
            else if(brr[i] == 4) four++;
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 0) continue;
            else if(arr[i] == 1) ans += zero;
            else if(arr[i] == 2)
            {
                ind = binarySearch(brr, brr.size(), arr[i]);
                if(ind != -1) ans += brr.size() - ind;
                ans -= three;
                ans -= four;
                ans += one + zero;
            }
            else if(arr[i] == 3)
            {
                ind = binarySearch(brr, brr.size(), arr[i]);
                if(ind != -1)  ans += brr.size() - ind; 
                ans +=  zero + one + two;
            }
            else
            {
                ind = binarySearch(brr, brr.size(), arr[i]);
                if(ind != -1)  ans += brr.size() - ind; 
                ans += zero + one;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends