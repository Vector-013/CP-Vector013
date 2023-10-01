#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    int t, n, m, cnt, pos1, pos2;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> n >> m;
        cin >> s1 >> s2;
        pos1 = -1, pos2 = -1;
        cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s1[i] == s1[i + 1])
                cnt++;
        }
        for (int i = 0; i < m - 1; i++)
        {
            if (s2[i] == s2[i + 1])
                cnt++;
        }
        if (cnt == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else if (cnt > 1)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            if (s1[n - 1] != s2[m - 1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}