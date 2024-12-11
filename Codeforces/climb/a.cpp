#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Fast exponentiation
long long mod_exp(long long base, long long exp, long long mod)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    const int MAX = 1000; // 2 * 500
    vector<long long> fact(MAX + 1, 1), power2(501, 1), inv2(501, 1);

    // Precompute factorials mod MOD
    for (int i = 2; i <= MAX; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Precompute powers of 2 and their inverses mod MOD
    for (int i = 1; i <= 500; ++i)
    {
        power2[i] = (power2[i - 1] * 2) % MOD;
        inv2[i] = mod_exp(power2[i], MOD - 2, MOD);
    }

    // Query result for any n
    int n;
    cout << "Enter n (0 <= n <= 500): ";
    cin >> n;
    if (n < 0 || n > 500)
    {
        cout << "Invalid n" << endl;
        return 0;
    }
    long long result = (fact[2 * n] * inv2[n]) % MOD;
    cout << "Result: " << result << endl;
    return 0;
}
