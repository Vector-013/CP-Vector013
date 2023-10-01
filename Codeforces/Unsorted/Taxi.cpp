#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, k, ans;
    cin >> n;
    float a[5] = {};
    while (n--)
    {
        cin >> k;
        a[k]++;
    }
    float m = max((a[1] - a[3]), (float)0);
    // ans = a[4] + a[3] + (max(a[1] - a[3], 0) + a[2] * 2 + 3) / 4; also works
    ans = a[4] + a[3] + ceil(a[2] / 2) + ceil((m - ((int)a[2] % 2) * 2) / 4);

    cout << ans << "\n ";
}