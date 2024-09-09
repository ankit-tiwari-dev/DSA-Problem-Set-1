//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, vector<int>& board, vector<vector<int>>& ans,
               vector<int>& LeftRow, vector<int>& UpperDiagonal,
               vector<int>& LowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (LeftRow[row] == 0 && LowerDiagonal[row+col] == 0 &&
                UpperDiagonal[n-1+col-row] == 0) {
                board[row] = col+1;
                LeftRow[row] = 1;
                LowerDiagonal[row+col] = 1;
                UpperDiagonal[n-1+col-row] = 1;
                solve(col + 1, board, ans, LeftRow, UpperDiagonal,
                      LowerDiagonal, n);
                board[row] = -1;
                LeftRow[row] = 0;
                LowerDiagonal[row+col] = 0;
                UpperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> board(n);

        for (int i = 0; i < n; i++) {
            board[i] = -1;
        }
        vector<int> LeftRow(n, 0), UpperDiagonal(2*n-1, 0),
            LowerDiagonal(2*n-1, 0);
        solve(0, board, ans, LeftRow, UpperDiagonal, LowerDiagonal, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends


// Leet code Solution
/*
class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& LeftRow, vector<int>& UpperDiagonal,
               vector<int>& LowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (LeftRow[row] == 0 && LowerDiagonal[row + col] == 0 &&
                UpperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                LeftRow[row] = 1;
                LowerDiagonal[row + col] = 1;
                UpperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, LeftRow, UpperDiagonal,
                      LowerDiagonal, n);
                board[row][col] = '.';
                LeftRow[row] = 0;
                LowerDiagonal[row + col] = 0;
                UpperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> LeftRow(n, 0), UpperDiagonal(2 * n - 1, 0),
            LowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, LeftRow, UpperDiagonal, LowerDiagonal, n);
        return ans;
    }
};
*/