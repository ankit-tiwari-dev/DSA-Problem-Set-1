//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    string decimalToAnyBase_Below_2_to_9(int n, int base)
    {
        string res = "";
        int cnt = 0;
        while(n > 0)
        {
            res += to_string(n % base);
            n /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string decimalToAnyBase_Below_11_to_15(int N, int B)
    {
        string res = "";
        while(N > 0)
        {
            if(N % B < 10)
                res += to_string(N % B);
            else 
                res += (char)('A' + (N % B) - 10);
            N /= B;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string getNumber(int B, int N)
    {
        if(B < 10) 
            return decimalToAnyBase_Below_2_to_9(N, B);
        else if(B > 10)
            return decimalToAnyBase_Below_11_to_15(N, B);
        else return to_string(N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int B,N;
        cin>>B>>N;
        Solution ob;
        string ans  = ob.getNumber(B,N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends