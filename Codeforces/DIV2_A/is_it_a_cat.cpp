#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s;
        for (int k = 0; k < n; k++)
        {
            if (s[k] < 96)
                s[k] = s[k] + 32;
        }
        char a = s[0];
        int m = 1;
        // for (int i = 1; i < n; i++)
        while (s[m])
        {
            if (s[m] == s[m - 1])
            {
                s.erase(s.begin() + m);
                continue;
            }
            else
                m++;
        }
        if (s == "meow")
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