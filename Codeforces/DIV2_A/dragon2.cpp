#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void sortv(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].first > v[j + 1].first)
            {
                int temp1 = v[j].first;
                v[j].first = v[j + 1].first;
                v[j + 1].first = temp1;

                int temp2 = v[j].second;
                v[j].second = v[j + 1].second;
                v[j + 1].second = temp2;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, n, a, b;
    cin >> s >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sortv(v);
    for (int i = 0; i < n; i++)
    {
        if (s >= v[i].first)
        {
            s += v[i].second;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
