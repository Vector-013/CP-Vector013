#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int a, n, pos, t;
    cin >> t;
    while (t > 0)
    {
        cin >> a >> n;
        if (n % 4 == 0)
        {
            cout << a << "\n";
        }
        else if (n % 4 == 1)
        {
            if (a % 2 == 0)
            {
                cout << a - n << "\n";
            }
            else
            {
                cout << a + n << "\n";
            }
        }
        else if (n % 4 == 2)
        {
            if (a % 2 == 0)
            {
                cout << a + 1 << "\n";
            }
            else
            {
                cout << a - 1 << "\n";
            }
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << a + n + 1 << "\n";
            }
            else
            {
                cout << a - n - 1 << "\n";
            }
        }
        t--;
    }
}