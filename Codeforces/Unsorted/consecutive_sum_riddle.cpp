#include <iostream>
using namespace std;
int main()
{
    long long int t, n, r, l;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (n % 2 == 1)
        {
            cout << (n - 1) / 2 << " " << (n + 1) / 2 << "\n";
        }
        else
        {
            cout << 1 - n << " " << n << "\n";
        }
    }
}