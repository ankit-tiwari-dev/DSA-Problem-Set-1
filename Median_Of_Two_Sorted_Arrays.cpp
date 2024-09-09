//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        
        int left = arr1.size() - 1;
        int right = 0;
        
        while(left >= 0 && right < arr2.size()-1)
        {
            if(arr1[left] > arr2[right])    
            {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            }
            else
            {
                left--;
                right++;
            }
        }
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        int median = 0;
        int n = arr1.size() + arr2.size();
        n /= 2;
        if(n-1 < arr1.size())
        {
            median += arr1[n-1];
            if(n < arr1.size())
                median += arr1[n];
            else
                median += arr2[arr1.size()-n];
        }
        else
        {
            median += arr2[arr1.size()-n-1];
            if((arr1.size()-n) > arr2.size())
                median += arr2[arr1.size()-n];
        }
        return median;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends