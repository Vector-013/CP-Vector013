#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    for (int p = 0; p < t; p++)
    {
        cin >> n;
        if (n == 1 || n == 2)
        {
            cout << 0 << "\n";
        }
        else
        {
            if (n % 2 == 0)
            {
                cout << (n / 2) - 1 << "\n";
            }
            else
            {
                cout << (n - 1) / 2 << "\n";
            }
        }
    }
}