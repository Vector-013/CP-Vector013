#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;

int mex_find(set<int> s)
{
    int mex = s.size();
    auto it = s.begin();
    for (int i = 0; i < s.size(); i++)
    {
        if (*it != i)
        {
            mex = i;
            break;
        }
        it++;
    }
    return mex;
}

void solve()
{
    int n;
    int mex = 0;
    cin >> n;
    int l = 0, r = n - 1;
    vector<int> v(n);
    set<int> s, s2;

    for (int q = 0; q < n; q++)
    {
        cin >> v[q];
        s.insert(v[q]);
    }
    mex = mex_find(s);

    if (count(v.begin(), v.end(), mex + 1))
    {

        while (v[l] != mex + 1)
            l++;
        while (v[r] != mex + 1)
            r--;
        for (int i = l; i <= r; i++)
            v[i] = mex;
        for (int i = 0; i < n; i++)
            s2.insert(v[i]);
        if (mex_find(s2) == mex + 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    else
    {
        int freq[mex] = {0};
        if (*max_element(v.begin(), v.end()) >= mex + 1)
            cout << "YES" << '\n';
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] < mex)
                {
                    if (freq[v[i]] == 0)
                        freq[v[i]]++;
                    else
                    {
                        cout << "YES" << '\n';
                        return;
                    }
                }
            }
            cout << "NO" << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}