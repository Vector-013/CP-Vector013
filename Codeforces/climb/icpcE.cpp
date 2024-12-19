#include <bits/stdc++.h>
using namespace std;
bool eval(string s)
{
    int i = 0;
    int n = s.size();
    vector<long long> v;
    vector<char> op;
    while (i < n)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
        string num = "";
        long long val = 0ll;
        if (s[i] == '0')
        {
            v.push_back(val);
            i++;
        }
        else
        {
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                i++;
            }
            if (num.size() > 10)
            {
                return false;
            }
            val = stoll(num);
            v.push_back(val);
        }
        if (i < n && (s[i] == '+' || s[i] == '-' || s[i] == '='))
        {
            op.push_back(s[i]);
            i++;
        }
        else if (i < n)
        {
            return false;
        }
    }
    i = 0;
    int j = 0;
    long long a = v[j];
    j++;
    while (i < op.size() && op[i] != '=')
    {
        if (op[i] == '+')
        {
            a += v[j];
            j++;
        }
        else
        {
            a -= v[j];
            j++;
        }
        i++;
    }
    long long b = v[j];
    j++;
    i++;
    while (i < op.size())
    {
        if (op[i] == '+')
        {
            b += v[j];
            j++;
        }
        else
        {
            b -= v[j];
            j++;
        }
        i++;
    }
    if (a == b)
        return true;
    else
        return false;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (eval(s))
    {
        cout << "Correct\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (s[i] >= '0' && s[i] <= '9')
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                string t = s;
                t.erase(t.begin() + i);
                t.insert(t.begin() + j, c);
                // cout << t << '\n';
                if (eval(t))
                {
                    cout << t << '\n';
                    return;
                }
            }
        }
    }
    cout << "Impossible\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}