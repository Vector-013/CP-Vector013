#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

class Solution
{
public:
    bool dfs(int i, int j, vector<vector<int>> &v)
    {
        if (i >= v[0].size() || j >= v.size() || i < 0 || j < 0)
            return false;
        if (i == v[0].size() - 1 && j == v.size() - 1 && v[i][j] >= 1)
            return true;
        if (v[i][j] == 2)
            return true;
        if (v[i][j] == 0 || v[i][j] == -1)
            return false;

        v[i][j] = -1;
        if (dfs(i + 1, j, v) || dfs(i - 1, j, v) || dfs(i, j + 1, v) || dfs(i, j - 1, v))
        {
            v[i][j] == 2;
            return true;
        }
        v[i][j] = -1;
        return false;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int maxi = -1e9;
        int start = grid[0][0];
        vector<vector<int>> v(grid[0].size(), vector<int>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] >= maxi)
                    maxi = grid[i][j];
            }
        }

        int b = (start + maxi) / 2;
        while (maxi != start)
        {
            b = (start + maxi) / 2;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] > b)
                        v[i][j] = 0;
                    else
                        v[i][j] = 1;
                }
            }

            if (dfs(0, 0, v))
            {
                maxi = b;
            }
            else
            {
                start = b + 1;
            }

            v.clear();
            v.resize(grid[0].size(), vector<int>(grid[0].size()));
        }

        return start;
    }
};