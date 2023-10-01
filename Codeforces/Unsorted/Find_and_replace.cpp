#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    int n;
    int cnt;
    char a;
    for (int m = 0; m < t; m++)
    {
        cin >> n;
        cin >> s;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            a = s[i];
            if (!(s[i] == '0' || s[i] == '1'))
            {
                if (i % 2 == 0)
                {
                    replace(s.begin(), s.end(), a, '1');
                    // cout << s
                    //    << "\n";
                }
                else
                {
                    replace(s.begin(), s.end(), a, '0');
                    // cout << s
                    //    << "\n";
                }
            }
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j] != s[j + 1])
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}