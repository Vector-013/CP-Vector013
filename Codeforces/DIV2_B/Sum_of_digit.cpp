#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
int power(int i)
{
    if (i == 0)
        return 1;
    int ans = 1;
    for (int k = 0; k < i; k++)
    {
        ans *= 10;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << '\n';
        return;
    }
    else
    {
        vector<int> a;
        vector<int> b;
        int dig = n % 10;
        int p = (dig + 1) / 2;
        int q = dig / 2;
        a.push_back(p);
        b.push_back(q);
        while (n >= 10)
        {
            n = n / 10;
            dig = n % 10;
            p = (dig + 1) / 2;
            q = dig / 2;
            if (accumulate(a.begin(), a.end(), 0) <= accumulate(b.begin(), b.end(), 0))
                a.push_back(p), b.push_back(q);
            else
                a.push_back(q), b.push_back(p);
        }
        int m = 0, n = 0;
        for (int i = 0; i < a.size(); i++)
        {
            m += a[i] * power(i);
        }
        for (int i = 0; i < b.size(); i++)
        {
            n += b[i] * power(i);
        }
        cout << m << " " << n << '\n';
        return;
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