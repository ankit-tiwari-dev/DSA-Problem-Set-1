//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<int> &visited, const vector<vector<int>> &adj, int node, int &cntNodes, int &cntEdges) {  
        visited[node] = 1;
        cntNodes++;
        cntEdges += adj[node].size();
        for (int neighbor : adj[node]) {  
            if (!visited[neighbor]) {  
                dfs(visited, adj, neighbor, cntNodes, cntEdges);  
            }  
        }  
    }  

    int findNumberOfGoodComponent(int e, int v, vector<vector<int>>& edges) {  
        vector<vector<int>> adj(v + 1);  
        for (const auto& edge : edges) {  
            adj[edge[0]].push_back(edge[1]);  
            adj[edge[1]].push_back(edge[0]);  
        }  

        vector<int> visited(v + 1, 0);  
        int count = 0;   
        
        for (int i = 1; i <= v; i++) {  
            int cntNodes = 0, cntEdges = 0;
            if (!visited[i]) {  
                dfs(visited, adj, i, cntNodes, cntEdges);  
                int val = cntNodes * (cntNodes-1);
                if(cntEdges == val)
                    count++;  
            }  
        }  
        return count;   
    }   
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends