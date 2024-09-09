#include <iostream>
#include "c++/algorithm"
using namespace std;
class fun
{
public:
    void isPalindrome(string &str)
    {
        string s = str;
        for (int i = 0; i < str.size() / 2; i++)
        {
            swap(str[i], str[str.size() - 1 - i]);
        }
        if (s == str)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
};

int main()
{
    string str;
    fun obj = fun();
    cout << "Enter String : ";
    cin >> str;
    obj.isPalindrome(str);
    return 0;
}