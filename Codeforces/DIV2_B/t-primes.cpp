#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int INF = 2e9;
#define make_pair
#define pb push_back
#define pop pop_back
typedef long long ll;
typedef long double ld;
bool isprime(ll sqr)
{
    if (sqr == 2)
        return true;
    if (sqr == 1 || sqr % 2 == 0)
        return false;
    for (int i = 3; i <= ceil(sqrt(sqr)); i += 2)
    {
        if (sqr % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    ll num;
    cin >> num;
    ll sqr = round(sqrtl(num));
    if (num == sqr * sqr && isprime(sqr))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
