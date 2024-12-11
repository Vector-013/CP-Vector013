#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.length();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({cnt, i+1});
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
    }
    auto comp = [&](auto p1, auto p2)
    {
        if (p1.first < p2.first)
            return true;
        else if (p1.first > p2.first)
            return false;
        return p1.second >= p2.second;
    };
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
    {
        //cout << v[i].first << " " << v[i].second << " ";
        cout << s[v[i].second - 1];
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}