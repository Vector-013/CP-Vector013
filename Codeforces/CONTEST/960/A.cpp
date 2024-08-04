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
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            if (cnt & 1)
            {
                cout << "yes\n";
                return;
            }
            else
            {
                cnt = 0;
            }
        }
        cnt++;
    }
    if (cnt & 1)
    {
        cout << "yes\n";
        return;
    }
    cout << "no\n";
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