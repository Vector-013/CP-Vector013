#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a[26];
    for (int i = 0; i < 26; i++)
        a[i] = 0;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 65]++;
    int cnt = 0, flag;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] & 1)
        {
            cnt++;
            flag = i;
        }
        if (cnt > 1)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    int n = s.length();
    string ans(n, '?');
    int ptr = 0;
    if (n & 1)
    {
        ans[n / 2] = flag + 65;
        a[flag]--;
    }
    for (int i = 0; i < 26; i++)
        a[i] /= 2;
    for (int i = 0; i < 26; i++)
    {
        while (a[i])
        {
            ans[ptr] = i + 65;
            ptr++;
            a[i]--;
        }
    }
    for (int i = n - 1; i >= n / 2; i--)
    {
        ans[i] = ans[n - 1 - i];
    }
    cout << ans;
}