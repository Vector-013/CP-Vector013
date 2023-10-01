#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, q, l, r, k, sum;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        sum = 0;
        cin >> n >> q;
        int arr[n];
        int arrsum[n + 1] = {};
        cin >> arr[0];
        arrsum[0] = 0;
        arrsum[1] = arr[0];
        for (int j = 1; j < n; j++)
        {
            cin >> arr[j];
            arrsum[j + 1] = arrsum[j] + arr[j];
        }
        for (int j = 0; j < q; j++)
        {
            sum = arrsum[n];
            cin >> l >> r >> k;
            sum = sum + (r - l + 1) * k - arrsum[r] + arrsum[l - 1];
            if (sum % 2 != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}