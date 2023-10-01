#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long double n;
        cin >> n;
        cout << (ll)(ceil(sqrt(n) - (ll)1)) << "\n";
    }
}