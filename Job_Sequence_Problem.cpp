//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution   
{  
public: 
    static bool comp(const Job &val1, const Job &val2)  
    {  
        return val1.profit > val2.profit;  
    }  
    
    pair<int, int> func(Job arr[], int n)   
    {  
        sort(arr, arr + n, comp);  

        int maxDeadline = 0;  
        for (int i = 0; i < n; i++) {  
            maxDeadline = max(maxDeadline, arr[i].dead);  
        }  
        
        vector<bool> slots(maxDeadline + 1, false);  
        int totalProfit = 0, jobCount = 0;  

        for (int i = 0; i < n; i++)   
        {  
            for (int j = min(maxDeadline, arr[i].dead); j > 0; j--)   
            {  
                if (!slots[j])   
                {  
                    slots[j] = true; 
                    jobCount++;        
                    totalProfit += arr[i].profit;  
                    break; 
                }  
            }  
        }  

        return {jobCount, totalProfit}; 
    }  

    vector<int> JobScheduling(Job arr[], int n)   
    {   
        pair<int, int> result = func(arr, n);  
        return {result.first, result.second};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends