#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> a[i];

        cout << a[0] << " ";
        for (int i = 1; i < n - 1; i++)
            cout << min(a[i], a[i - 1]) << " ";
        cout << a[n - 2] << "\n";
    }
}