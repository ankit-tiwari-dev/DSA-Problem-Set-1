#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
/*
class Solution {
public:
    bool capacityCheck(vector<int>&weights, int capacity, int days)
    {
        int sum = 0;
        int countDay = 1;
        for(int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if(sum >= capacity)
            {
                sum -= weights[i];
                countDay++;
                sum = weights[i];
            }
        }
        if(countDay <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            if(maxi < weights[i])
                maxi = weights[i];
            sum += weights[i];
        }
        int ans = 0;
        int low = maxi; 
        int high = sum; 

        while(low <= high)
        {
            int mid = (low + high)/2;
            if(capacityCheck(weights, mid, days))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
}; */
class Solution {
public:
    int findDays(vector<int>&weights, int capacity)
    {
        int load = 0;
        int days = 1;
        for(int i = 0; i < weights.size(); i++)
        {
            if(weights[i] + load > capacity)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            if(maxi < weights[i])
                maxi = weights[i];
            sum += weights[i];
        }
        int ans = 0;
        int low = maxi; 
        int high = sum; 

        while(low <= high)
        {
            int mid = (low + high)/2;
            int NoOfDays = findDays(weights, mid);
            if(NoOfDays <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};
int main()
{
    vector<int> weights;
    int n;
    cout<<"Enter the product size : ";
    cin>>n;
    cout<<"Enter Array : "<<endl;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin>> val;
        weights.push_back(val);
    }
    int days;
    cout<<"Enter day : ";
    cin>>days;
    Solution ob;
    cout<<ob.shipWithinDays(weights, days);
    return 0;
}