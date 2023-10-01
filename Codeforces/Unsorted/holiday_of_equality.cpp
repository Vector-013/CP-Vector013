#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] < v[n - 1])
            sum = sum + v[n - 1] - v[i];
    }
    cout << sum << "\n";
}