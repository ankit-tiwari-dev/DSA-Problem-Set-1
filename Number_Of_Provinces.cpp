//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int curr)
    {
        vis[curr] = 1;
        for(int i = 0; i < vis.size(); i++)
            if(i != curr && adj[curr][i] && !vis[i])
                dfs(adj, vis, i);
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int cnt = 0;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
        {
            cnt += !vis[i] ? dfs(adj, vis, i), 1 : 0;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends