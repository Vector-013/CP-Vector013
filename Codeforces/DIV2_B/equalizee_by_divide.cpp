#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int minpos(vector<int> v)
{
    int minpos = 0;
    int min = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < min)
        {
            minpos = i;
            min = v[i];
        }
    }
    return minpos;
}
bool notequal(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[0])
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, itr, cnt = 0;
    bool lie = 0;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
        {
            lie = 1;
        }
    }
    if (lie && notequal(v))
    {
        cout << "-1"
             << "\n";
        return;
    }
    if (!notequal(v))
    {
        cout << 0 << endl;
        return;
    }
    while (notequal(v))
    {
        itr = minpos(v);
        for (int i = 0; i < n; i++)
        {
            if (v[i] != v[itr])
            {
                vp.push_back({i, itr});
                cnt++;
                if (v[i] % v[itr] == 0)
                    v[i] = v[i] / v[itr];
                else
                    v[i] = v[i] / v[itr] + 1;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}