#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
class freq
{
public:
    static void LowerCaseLetterFrequency(string &s)
    {
        int q;

        int hash[27] = {0};
        cin >> q;

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        while (q--)
        {
            char c;
            cin >> c;
            cout << hash[c - 'a'] << endl;
        }
    }
    static void UpperCaseLetterFrequency(string &s)
    {
        int q;

        int hash[27] = {0};
        cin >> q;

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'A']++;
        }
        while (q--)
        {
            char c;
            cin >> c;
            cout << hash[c - 'A'] << endl;
        }
    }
    static void MixedCaseLetterFrequency(string &s)
    {
        int q;

        int hash[256] = {0};
        cin >> q;

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }
        while (q--)
        {
            char c;
            cin >> c;
            cout << hash[c] << endl;
        }
    }
    static void Array_occur(int arr[], int n)
    {

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }

        // Iterate the map
        for (auto it : mpp)
        {
            cout << it.first << " -> " << it.second << endl;
        }

        int q;
        cin >> q;
        while (q--)
        {
            int num;
            cin >> num;
            cout << mpp[num] << endl;
        }
    }
};
int main()
{
    freq obj = freq();
    /* string str;
    int query;
    cout << "Enter String : " << endl;
    cin >> str;
    obj.LowerCaseLetterFrequency(str);
    obj.UpperCaseLetterFrequency(str);
    obj.MixedCaseLetterFrequency(str); */

    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    int arr[n];

    cout << endl
         << "Enter Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    obj.Array_occur(arr, n);
    return 0;
}