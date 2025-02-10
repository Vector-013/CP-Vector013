
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

template <class T, class U>
// T -> node, U->update.
struct Lsegtree
{
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element;
    U identity_update;
    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }
    T combine(T l, T r, bool is_or)
    {
        // change this function as required.
        // T ans = (l + r);
        T ans = is_or ? l | r : l ^ r;
        return ans;
    }
    void buildUtil(ll v, ll tl, ll tr, vector<T> &a, bool is_or)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a, !is_or);
        buildUtil(2 * v + 2, tm + 1, tr, a, !is_or);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2], is_or);
    }
    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        // T ans = (tr - tl + 1) * upd;
        // return ans;
        return upd;
    }
    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = new_upd;
        // ans = new_upd;
        return ans;
    }
    void push_down(ll v, ll tl, ll tr)
    {
        if (lazy[v] == identity_update)
            return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r, bool is_or)
    {
        push_down(v, tl, tr);
        if (l > r)
            return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r, !is_or), queryUtil(2 * v + 2, tm + 1, tr, l, r, !is_or), is_or);
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd, bool is_or)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)
            return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd, !is_or);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd, !is_or);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2], is_or);
        }
    }

    void build(vector<T> a)
    {
        assert(a.size() == n);
        buildUtil(0, 0, n - 1, a, true);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r, true);
    }
    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd, true);
    }
};

void solve()
{
    int x, m;
    cin >> x >> m;
    int n = (1 << x);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Lsegtree<int, int> st(n, 0, 0);
    st.build(a);
    cout << st.query(0, n - 1) << '\n';

    for (int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;
        st.update(p - 1, p - 1, b);
        cout << st.query(0, n - 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
