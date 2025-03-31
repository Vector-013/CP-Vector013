#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int cnt = 0;

        map<int, int> tuples;

        for (auto a : nums)
            for (auto b : nums)
                ++tuples[a & b];
        for (auto a : nums)
            for (auto t : tuples)
                if ((t.first & a) == 0)
                    cnt += t.second;
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 6, 7};
    cout << s.countTriplets(nums) << endl;
    return 0;
}