#include <bits/stdc++.h>
using namespace std;
long long psum[300001], psum2[300001], psum3[300001], pos[300001];
long long qsum(long long p, long long n)
{
    if (p == 0)
        return 0;
    long long l, r, mid, ans;
    l = 0;
    r = n + 1;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (pos[mid] <= p)
            l = mid;
        else
            r = mid;
    }
    ans = psum3[l];
    p -= pos[l];
    p += l;
    ans += psum2[p] - psum2[l] - (p - l) * (psum[l]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    long long n, q, i, l, r;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> psum[i + 1];
        psum[i + 1] += psum[i];
        psum2[i + 1] = psum[i + 1];
        psum2[i + 1] += psum2[i];
        pos[i + 1] = n - i;
        pos[i + 1] += pos[i];
    }
    for (i = 1; i <= n; i++)
    {
        psum3[i] = psum2[n] - psum2[i - 1] - (n - i + 1) * (psum[i - 1]);
        psum3[i] += psum3[i - 1];
    }
    for (cin >> q; q > 0; q--)
    {
        cin >> l >> r;
        cout << qsum(r, n) - qsum(l - 1, n) << '\n';
    }
    return 0;
}