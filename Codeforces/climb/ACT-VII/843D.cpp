#include <bits/stdc++.h>
using namespace std;
int a[300000], frm[300000];
bool ntprime[300001] = {};
int prime[300000], val[300001], pricnt = 0, N = 300000;
void gen()
{
    int i, j;
    ntprime[1] = 1;
    val[1] = 1;
    for (i = 2; i <= N; i++)
    {
        if (!ntprime[i])
        {
            prime[pricnt] = i;
            val[i] = i;
            pricnt++;
        }
        for (j = 0; j < pricnt && i * prime[j] <= N; j++)
        {
            ntprime[i * prime[j]] = 1;
            val[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
queue<int> bfs;
vector<int> dv[300001], ans;
vector<int>::iterator it;
int mem[300001] = {}, vis[300001] = {};
int main(int argc, char **argv)
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, s, t, i, j, lst, k;
    gen();
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> s >> t;
    s--;
    t--;
    if (s == t)
    {
        cout << "1\n"
             << s + 1 << '\n';
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        lst = -1;
        for (j = a[i]; j > 1; j /= val[j])
        {
            if (lst != val[j])
                dv[val[j]].push_back(i);
            lst = val[j];
        }
    }
    bfs.push(s);
    vis[s] = 1;
    while (!bfs.empty())
    {
        k = bfs.front();
        bfs.pop();
        for (j = a[k]; j > 1; j /= val[j])
        {
            if (mem[val[j]] == 0)
            {
                mem[val[j]] = 1;
                for (it = dv[val[j]].begin(); it != dv[val[j]].end(); it++)
                {
                    if (vis[*it] == 0)
                    {
                        vis[*it] = 1;
                        bfs.push(*it);
                        frm[*it] = k;
                    }
                }
            }
        }
    }
    if (vis[t] == 0)
        cout << "-1\n";
    else
    {
        for (i = t; i != s; i = frm[i])
            ans.push_back(i);
        cout << ans.size() + 1 << '\n'
             << s + 1 << ' ';
        for (i = ans.size() - 1; i > -1; i--)
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}