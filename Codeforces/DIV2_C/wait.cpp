#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
#define pb push_back
#define pp pop_back
#define f(i, n) for (int i = 0; i < n; i++)
ll maxsubsum(vector<ll> v)
{
    ll s = 0, start = 0, end = 0, currsum = 0, maxsum = -linf;
    for (int i = 0; i < v.size(); i++)
    {
        currsum += v[i];
        if (currsum > maxsum)
        {
            start = s;
            end = i;
            maxsum = currsum;
        }
        if (currsum < 0) // maxlen (<= for minlen)
        {
            currsum = 0;
            s = i + 1;
        }
    }
    return maxsum;
}
int BinarySearch(vector<int> v, int key)
{
    int s = 0;
    int e = v.size();
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] > key)
            e = mid - 1;
        else if (v[mid] < key)
            s = mid + 1;
        else
            return mid;
    }
    return -1;
}
int gcd(int x, int y)
{
    int a = max(x, y);
    int b = min(x, y);
    int rem = a % b;
    while (rem != 0)
    {
        a = b;
        b = rem;
        rem = a % b;
    }
    return b;
}
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n--)
        ans *= a;
    return ans;
}
bool isprime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool pairsort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
void addEdge(int x, int y, vector<vector<int>> &tree)
{
    tree[x].pb(y);
    tree[y].pb(x);
}
int leaf(int node, vector<vector<int>> &tree, int cnt)
{
    int sum = cnt;
    if (tree[node].size() == 1 && node != 1)
        return cnt + 1;
    f(i, tree[node].size())
    {
        if (tree[node][i] > node)
            sum += leaf(tree[node][i], tree, cnt);
    }
    return sum;
}
void solve()
{
    int n, a, b, q, x, y;
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>());
    f(i, n - 1)
    {
        cin >> a >> b;
        addEdge(a, b, tree);
    }
    cin >> q;
    f(i, q)
    {
        cin >> x >> y;
        cout << leaf(x, tree, 0) * leaf(y, tree, 0) << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}