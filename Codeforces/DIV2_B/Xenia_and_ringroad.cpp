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

void solve()
{
    ll n, t, time = 0;
    cin >> n >> t;
    ll a[t] = {};
    for (int i = 0; i < t; i++)
        cin >> a[i];
    time = a[0] - 1;
    for (int i = 1; i < t; i++)
    {
        if (a[i] > a[i - 1])
            time += a[i] - a[i - 1];
        else if (a[i] == a[i - 1])
            time += 0;
        else
            time += n + a[i] - a[i - 1];
    }
    cout << time << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}