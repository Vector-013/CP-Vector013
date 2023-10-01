#include <iostream>
using namespace std;
int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int a = n * m;
    char c[10001];

    for (int i = 0; i < a; i++)
    {
        cin >> c[i];
        if (c[i] != 'W' && c[i] != 'B' && c[i] != 'G')
        {
            cnt++;
        }
        }

    if (cnt > 0)
    {
        cout << "#Color"
             << "\n";
    }
    else
    {
        cout << "#Black&White"
             << "\n";
    }
}