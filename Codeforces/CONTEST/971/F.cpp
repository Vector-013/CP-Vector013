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
ll max(ll a, ll b)
{
	if (a >= b)
		return a;
	else
		return b;
}
void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	vector<ll> s(n + 1);
	s[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] += s[i - 1] + a[i - 1];
	}

	auto sum_so_far = [&](ll pos)
	{
		ll cycle = pos / n;
		ll np = pos % n;
		ll sum = cycle * s[n];

		if (np < n - cycle)
		{
			sum += s[cycle + np + 1] - s[cycle];
		}
		else
		{
			sum += s[n] - s[cycle] + s[np - n + cycle + 1];
		}
		return sum;
	};

	for (ll i = 0; i < q; i++)
	{
		ll l, r;
		cin >> l >> r;
		r--;
		l--;
		ll ans = sum_so_far(r);
		if (l > 0)
			ans -= sum_so_far(l - 1);
		//cout << sum_so_far(r) << " " << sum_so_far(l - 1) << '\n';
		cout << ans << '\n';
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