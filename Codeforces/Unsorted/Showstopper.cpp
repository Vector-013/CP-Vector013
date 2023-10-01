#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a, b, am, bm, minn, maxx;
    vector<int> v1;
    vector<int> v2;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < n)
            {
                cin >> a;
                v1.push_back(a);
            }
            else
            {
                cin >> b;
                v2.push_back(b);
            }
        }
        am = v1[n - 1];
        bm = v2[n - 1];
        for (int i = 0; i < n; i++)
        {
            maxx = max(am, bm);
            minn = min(am, bm);
            if ((max(v1[i], v2[i]) <= maxx) && (min(v1[i], v2[i]) <= minn))
            {
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

        v1.clear();
        v2.clear();
        t--;
    }
}