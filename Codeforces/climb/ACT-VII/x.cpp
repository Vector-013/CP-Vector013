#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        if (!(cin >> n))
            return 0;
        std::vector<int> x(n + 1);
        std::vector<bool> appear(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            if (x[i] >= 1 && x[i] <= n)
                appear[x[i]] = true;
        }
        int
            candidate = -1;
        for (int v = 1; v <= n; v++)
        {
            if (!appear[v])
            {
                candidate = v;
                break;
            }
        }
        if (candidate != -1)
        {
            int other = (candidate == 1 ? 2 : 1);
            cout << "? " << candidate << " " << other << "\n"
                 << flush;
            int response;
            cin >> response;
            if (response == -1)
                return 0;
            if (response == 0)
                cout << "! A" << "\n"
                     << flush;
            else
                cout << "! B"
                     << "\n"
                     << flush;
        }
        else
        {
            int i_min = 1, i_max = 1;
            for (int i = 1; i <= n; i++)
            {
                if (x[i] < x[i_min])
                    i_min = i;
                if (x[i] > x[i_max])
                    i_max =
                        i;
            }
            int diff = abs(x[i_min] - x[i_max]);
            cout << "? " << i_min << " "
                 << i_max << "\n"
                 << flush;
            int r;
            cin >> r;
            if (r == -1)
                return 0;
            if (r < diff)
            {
                cout << "! A" << "\n"
                     << flush;
            }
            else if (r > diff)
            {
                cout << "! B" << "\n"
                     << flush;
            }
            else
            {
                cout << "? " << i_max << " " << i_min
                     << "\n"
                     << flush;
                int r2;
                cin >> r2;
                if (r2 == -1)
                    return 0;
                if (r2 ==
                    diff)
                    cout << "! B" << "\n"
                         << flush;
                else
                    cout << "! A" << "\n"
                         << flush;
            }
        }
    }
    return 0;
}