//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> arr) {
        
        sort(arr.begin(), arr.end());
        long long int product = 0;
        
        for(long i = 1; i < arr.size(); i++)
        {
            product = (long long int)product + (long long int)(arr[i] * i);
        }
        product = (long long int)(product % (1000000000 + 7));
        
        return product;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends