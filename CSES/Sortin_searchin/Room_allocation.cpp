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

typedef struct
{
    int first, second, third;
} trip;
bool operator<(trip t1, trip t2)
{
    return t1.third < t2.third;
}
bool tripsort1(trip p1, trip p2)
{
    return p1.first < p2.first;
}
bool tripsort2(trip p1, trip p2)
{
    return p1.second < p2.second;
}
void solve()
{
    int n, a, b;
    cin >> n;
    vector<trip> x(n);
    vector<trip> y(n);
    // map<pair<int, int>, int> rank;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x[i] = {a, b, i};
        y[i] = {a, b, i};
    }
    sort(x.begin(), x.end(), tripsort1);
    sort(y.begin(), y.end(), tripsort2);
    int i = 0, j = 0, cnt = 0, maxi = 0;
    while (i < n && j < n)
    {
        while (i < n && x[i].first <= y[j].second)
        {
            cnt++;
            maxi = max(maxi, cnt);
            i++;
        }
        while (j < n && x[i].first > y[j].second)
        {
            cnt--;
            j++;
        }
    }
    i = 0, j = 0;
    cout << maxi << '\n';
    map<trip, int> rom;
    set<int> s;
    for (int i = 1; i <= maxi; i++)
        s.insert(i);
    vector<int> c(n);
    while (i < n && j < n)
    {
        while (i < n && x[i].first <= y[j].second)
        {
            c[x[i].third] = *s.begin();
            rom[x[i]] = *s.begin();
            s.erase(s.begin());
            i++;
        }
        while (j < n && x[i].first > y[j].second)
        {
            int a = rom[(y[j])];
            s.insert((rom[y[j]]));
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}