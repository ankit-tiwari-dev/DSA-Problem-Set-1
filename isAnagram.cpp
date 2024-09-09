//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isAnagram(string a, string b) {  
        if (a.length() != b.length()) return false; 
        map<char, int> charCount;  
  
        for (char c : a) {  
            charCount[c]++;  
        }  
        for (char c : b) {  
            charCount[c]--;  
            if (charCount[c] < 0) return false; 
        } 
        return true; 
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends