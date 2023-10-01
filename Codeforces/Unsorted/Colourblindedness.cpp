#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t, n, cnt = 0;
    string s1, s2;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n >> s1 >> s2;
        cnt = 0;
        for (int k = 0; k < n; k++)
        {
            if (s1[k] == s2[k] || (s1[k] == 'G' && s2[k] == 'B') || (s2[k] == 'G' && s1[k] == 'B'))
            {
                cnt++;
            }
        }
        if (cnt == n)
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