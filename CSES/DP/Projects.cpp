#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
struct event
{
    int start, end, profit;
};

bool comp(event e1, event e2) { return (e1.start < e2.start); }

vector<event> events;
vector<int> dp;

int solve(int i)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int p = events[i].profit;
    int ans = solve(i + 1);
    event e = {events[i].end + 1, events[i].end + 1, 0};
    int ind = lower_bound(events.begin(), events.end(), e, comp) - events.begin();
    if (ind != n)
    {
        ans = max(ans, p + solve(ind));
    }
    else
        ans = max(ans, p);
    return dp[i] = ans;
}

int32_t main()
{
    cin >> n;
    events.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> events[i].start >> events[i].end >> events[i].profit;
    }
    sort(events.begin(), events.end(), comp);
    dp.assign(n + 1, -1);
    cout << solve(0);
    return 0;
}