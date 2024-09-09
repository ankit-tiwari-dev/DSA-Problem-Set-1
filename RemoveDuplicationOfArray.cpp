#include <iostream>
#include <vector>
#include <set>
using namespace std;

void removeDuplicate(vector<int> arr)
{
    set<int> st;

    for (int i : arr)
        st.insert(i);

    for (auto i : st)
        cout << i << " "; 
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5};

    removeDuplicate(arr);
    return 0;
}