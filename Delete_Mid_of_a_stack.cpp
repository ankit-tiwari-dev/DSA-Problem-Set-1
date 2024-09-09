//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& st, int sizeOfStack) {
        vector<int> arr;
        
        for(int i = 0; i < sizeOfStack; i++)
        {
            if(i != (sizeOfStack/2))
            {
                arr.push_back(st.top());
                st.pop();
            }
            else st.pop();
        }
        
        for(int i = arr.size()-1; i >= 0; i--)
            st.push(arr[i]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends