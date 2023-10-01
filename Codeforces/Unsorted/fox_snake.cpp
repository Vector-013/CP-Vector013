#include <iostream>
#include <string>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    char h = '#';
    char p = '.';
    for (int i = 1; i < m + 1; i++)
    {
        if (i % 2 == 1)
            cout << string(n, h) << "\n";

        else if (i % 4 == 2)
            cout << string(n - 1, p) << h << "\n";

        else
            cout << h << string(n - 1, p) << "\n";
    }
}