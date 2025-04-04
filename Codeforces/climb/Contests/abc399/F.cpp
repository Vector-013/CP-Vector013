#include <bits/stdc++.h>
using namespace std;

template <typename T>
T mod_inv_in_range(T a, T m)
{
    // assert(0 <= a && a < m);
    T x = a, y = m;
    // coeff of a in x and y
    T vx = 1, vy = 0;
    while (x)
    {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    assert(y == 1);
    return vy < 0 ? m + vy : vy;
}

template <typename T>
struct extended_gcd_result
{
    T gcd;
    T coeff_a, coeff_b;
};
template <typename T>
extended_gcd_result<T> extended_gcd(T a, T b)
{
    T x = a, y = b;
    // coeff of a and b in x and y
    T ax = 1, ay = 0;
    T bx = 0, by = 1;
    while (x)
    {
        T k = y / x;
        y %= x;
        ay -= k * ax;
        by -= k * bx;
        std::swap(x, y);
        std::swap(ax, ay);
        std::swap(bx, by);
    }
    return {y, ay, by};
}

template <typename T>
T mod_inv(T a, T m)
{
    a %= m;
    a = a < 0 ? a + m : a;
    return mod_inv_in_range(a, m);
}

template <int MOD_>
struct modnum
{
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    int v;

public:
    modnum() : v(0) {}
    modnum(int64_t v_) : v(int(v_ % MOD))
    {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream &operator<<(std::ostream &out, const modnum &n) { return out << int(n); }
    friend std::istream &operator>>(std::istream &in, modnum &n)
    {
        int64_t v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
    friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }

    modnum inv() const
    {
        modnum res;
        res.v = mod_inv_in_range(v, MOD);
        return res;
    }
    friend modnum inv(const modnum &m) { return m.inv(); }
    modnum neg() const
    {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum &m) { return m.neg(); }

    modnum operator-() const
    {
        return neg();
    }
    modnum operator+() const
    {
        return modnum(*this);
    }

    modnum &operator++()
    {
        v++;
        if (v == MOD)
            v = 0;
        return *this;
    }
    modnum &operator--()
    {
        if (v == 0)
            v = MOD;
        v--;
        return *this;
    }
    modnum &operator+=(const modnum &o)
    {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator-=(const modnum &o)
    {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator*=(const modnum &o)
    {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    modnum &operator/=(const modnum &o)
    {
        return *this *= o.inv();
    }

    friend modnum operator++(modnum &a, int)
    {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum &a, int)
    {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
    friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};

template <typename T>
T pow(T a, long long b)
{
    assert(b >= 0);
    T r = 1;
    while (b)
    {
        if (b & 1)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

using num = modnum<998244353>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector binom(k + 1, vector<num>(k + 1));
    for (int i = 0; i <= k; i++)
    {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
        }
    }
    vector dp(n + 1, vector<num>(k + 1));
    num ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<num> pw(k + 1); // pw[j] = (a[i])^j
        pw[0] = 1;
        for (int j = 0; j < k; j++)
            pw[j + 1] = pw[j] * a[i];

        dp[i][0] += 1;
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; j + l <= k; l++)
            {
                dp[i + 1][j + l] += dp[i][j] * binom[k - j][l] * pw[l];
            }
        }
        ans += dp[i + 1][k];
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
