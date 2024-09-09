//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int x, vector<int> &arr1, vector<int> &arr2) {
        vector<pair<int, int>> ans;
        map<int, int> mpp;
        for(int i = 0; i < arr2.size(); i++)
            mpp[arr2[i]] = i;
        for(auto it : arr1)
        {
            int find = x - it;
            if(mpp.find(find) != mpp.end())
            {
                int ind = mpp[find];
                ans.push_back({it, arr2[ind]});
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr1;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2); // Read the entire line for the array elements
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(x, arr1, arr2);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else {
            for (int i = 0; i < sz; i++) {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends