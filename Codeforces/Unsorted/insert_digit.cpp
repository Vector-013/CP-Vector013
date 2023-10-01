#include <iostream>
#include <string>
using namespace std;
void solve()
{
    static string s;
    int n, pos = 0;
    char d;
    cin >> n >> d >> s;
    for (int i = 0; i < n; i++)
    {
        if (d == '0')
        {
            s = s + "0";
            break;
        }
        else if (s[i] >= d)
        {
            if (i == n - 1)
                s = s + string(1, d);
            continue;
        }

        else
        {
            s.insert(i, 1, d);
            break;
        }
    }
    cout << s << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }
}