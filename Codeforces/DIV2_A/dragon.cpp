#include <iostream>
#include <vector>
#include <algorithm>
#define q v[i].first
#define w v[i].second
using namespace std;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, n, x, y;
    cin >> s >> n;
    int sum = s; // fight in any order
    vector<pair<int, int>> v;
    for (int j = 0; j < n; j++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), pair_first_sort);
    for (int i = 0; i < n; i++)
    {
        if (sum > q)
        {
            sum = sum + w;
            if (i == n - 1)
            {
                cout << "YES"
                     << "\n";
            }
            continue;
        }
        else
        {
            cout << "NO"
                 << "\n";
            break;
        }
    }
}
