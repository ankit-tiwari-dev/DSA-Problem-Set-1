#include <iostream>
#include <vector>
using namespace std;
//Time Complexity :- O(log (n * m));
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (mat[row][col] == target) return true;
            else if (mat[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

//Time Complexity :- O(n) * O(log n);

class Solution {
public:
    bool binary_search(vector<int>&arr, int target)
    {
        int low = 0;
        int high = arr.size()-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid] == target)    return true;           
            else if(arr[mid] < target)   low = mid +1;
            else high = mid -1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] <= target && mat[i][m-1] >= target)
            {
                return binary_search(mat[i], target);
            }
        }
        return false;
    }
};