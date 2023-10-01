#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int r, g, b;
    cin >> r >> g >> b;
    long long int s = r + g + b;
    if (r % 3 + g % 3 + b % 3 == 3 && (r % 3) * (b % 3) * (g % 3) == 0 || (r % 3 + g % 3 + b % 3 == 4 && r * g * b == 0))
    {
        cout << (s / 3) - 1 << "\n";
    }
    else
    {
        cout << s / 3 << "\n";
    }
}