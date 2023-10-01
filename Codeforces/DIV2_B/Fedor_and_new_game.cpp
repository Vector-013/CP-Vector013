#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int INF = 2e9;
#define make_pair
#define pb push_back
#define pop pop_back
typedef long long ll;

string bit20(int x, string s)
{
    for (int i = 19; i >= 0; i--)
    {
        if (x / (int)pow(2, i) == 0)
        {
            s[19 - i] = '0';
        }
        else
        {
            s[19 - i] = '1';
            x = x % (int)pow(2, i);
        }
    }
    return s;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}