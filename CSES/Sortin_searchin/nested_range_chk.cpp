
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
using namespace std;
#define endl "\n"
#define ll long long int
#define ignore cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define debug(x) cerr << x << endl;
#define here fprintf(stderr, "====I am Here====\n");
#define vi vector<int>

bool cmp(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
    if (p1.second.first != p2.second.first)
    {
        return p1.second.first < p2.second.first;
    }
    return p1.second.second > p2.second.second;
}

int main()
{
    Boost;
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({i, {a, b}});
    }
    sort(v.begin(), v.end(), cmp);
    int start = v[0].second.first, end = 0;
    vector<pair<int, int>> ans1;
    for (auto i : v)
    {
        int b = i.second.second;
        if (end >= b)
        {
            ans1.push_back({i.first, 1});
        }
        else
        {
            ans1.push_back({i.first, 0});
            end = b;
        }
    }
    vector<pair<int, int>> ans2;
    int e = 2e9;
    for (int i = n - 1; i >= 0; i--)
    {
        int index = v[i].first;
        int b = v[i].second.second;
        if (e <= b)
        {
            ans2.push_back({index, 1});
        }
        else
        {
            e = b;
            ans2.push_back({index, 0});
        }
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    for (int i = 0; i < n; i++)
    {
        cout << ans2[i].second << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans1[i].second << " ";
    }
    cout << endl;
    return 0;
}