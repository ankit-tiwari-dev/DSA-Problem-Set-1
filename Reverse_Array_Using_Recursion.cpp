#include <iostream>
using namespace std;
void f(int a[], int n, int i)
{
    if (i >= n / 2)
        return;
    swap(a[i], a[n - i - 1]);
    f(a, n, i + 1);
}
int main()
{
    int n;

    cout << "Enter Size : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter A[" << (i + 1);
        cout << "] : ";
        cin >> arr[i];
    }
    f(arr, n, 0);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
/* #include <iostream>
using namespace std;
void f(int l, int r, int a[])
{
    if (l >= r)
        return;
    swap(a[l], a[r]);
    f(l + 1, r - 1, a);
}
int main()
{
    int n;

    cout << "Enter Size : ";
    cin >> n;

    cout << "Enter Array : ";
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    f(0, n - 1, arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
} */