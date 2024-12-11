#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    string s;
    cin >> s;
    map<char, int> mpv;
    mpv['A'] = count(s.begin(), s.end(), 'A');
    mpv['E'] = count(s.begin(), s.end(), 'E');
    mpv['I'] = count(s.begin(), s.end(), 'I');
    mpv['O'] = count(s.begin(), s.end(), 'O');
    mpv['U'] = count(s.begin(), s.end(), 'U');
    mpv['Y'] = count(s.begin(), s.end(), 'Y');
    int vc = mpv['A'] + mpv['E'] + mpv['I'] + mpv['O'] + mpv['U'];
    int yc = mpv['Y'];
    map<char, int> mpc;
    for (auto &c : s)
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
            continue;
        mpc[c]++;
    }
    int nc = mpc['N'];
    int gc = mpc['G'];
    int rst = s.length() - vc - yc - nc - gc;
    // find possible combinations wih 2N 2G and a vowel
    int ans = 0;
    int s1 = min(min(nc, gc) / 2, vc);
    ans += s1 * 5;
    vc -= s1;
    nc -= s1 * 2;
    gc -= s1 * 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}