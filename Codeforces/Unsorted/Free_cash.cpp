#include <iostream>
#include <vector>
#define q v[j].first
#define w v[j].second
#define e v[j - 1].first
#define r v[j - 1].second
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> v;
    int n, h, m, cnt = 1, maxneed = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> m;
        v.push_back({h, m});
    }
    for (int j = 1; j < n; j++)
    {
        if ((q == e && w - r == 0))
        {
            cnt++;
            if (cnt > maxneed)
                maxneed = cnt;
        }
        else
        {
            cnt = 1;
        }
    }
    cout << maxneed << "\n";
}