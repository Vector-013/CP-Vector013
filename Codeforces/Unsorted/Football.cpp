#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int curr = s[0], cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (curr == s[i])
            cnt++;
        else
        {
            cnt = 1;
            curr = s[i];
        }
        if (cnt == 7)
        {
            cout << "YES"
                 << "\n";
            break;
        }
    }
    if (cnt < 7)
    {
        cout << "NO"
             << "\n";
    }
}
