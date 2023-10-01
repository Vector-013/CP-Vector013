#include <iostream>
using namespace std;
int main()
{
    int t, n, s1, s2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int arr[n];
        s1 = 0;
        s2 = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if (arr[j] % 2 == 0)
            {
                s1 = s1 + arr[j];
            }
            else
            {
                s2 = s2 + arr[j];
            }
        }

        if (s1 > s2)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}