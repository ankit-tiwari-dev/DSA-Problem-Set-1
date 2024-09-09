//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    string decimalToBinary(int a)
    {
        string res = "";
        while(a > 0)
        {
            res += to_string(a % 2);
            a /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string binaryToDecimal(int b)
    {
        int cnt = 0;
        int res = 0;
        while(b > 0)
        {
            res += (b%10) * (int)pow(2, cnt++);
            b /= 10;
        }
        return to_string(res);
    }
    
    string decimalToHexaDecimal(int c)
    {
        string res = "";
        while (c > 0)
        {  
            if (c % 16 < 10) res += to_string(c % 16);
            else  res += (char)('A' + ((c % 16) - 10));
            c /= 16;  
        }  
        reverse(res.begin(), res.end());
        return res;
    }
    
    string hexadecimalToDecimal(string d)
    {
        int res = 0;
        for(int i = 0; i < d.length(); i++)
        {
            char ch = d[i];
            int value = 0;
            if(ch >= 'A' && ch <= 'F')
                value = ch - 'A' + 10;
            else if(ch >= '0' && ch <= '9')
                value = ch - '0';
                
            res = res* 16 + value;
        }
        return to_string(res);
    }
    
    vector<string> convert(int a, int b, int c, string d)
    {
        vector<string> st;
        st.push_back(decimalToBinary(a));
        st.push_back(binaryToDecimal(b));
        st.push_back(decimalToHexaDecimal(c));
        st.push_back(hexadecimalToDecimal(d));
        return st;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        string d;
        cin>>a>>b>>c>>d;
        
        Solution ob;
        vector<string> ans = ob.convert(a,b,c,d);
        
        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0; 
}
// } Driver Code Ends