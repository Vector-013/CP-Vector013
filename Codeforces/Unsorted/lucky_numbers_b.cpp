#include <string>
#include <iostream>

using namespace std;
int main()
{
    // char s[100000000];
    string s;
    int cnt4 = 0, cnt7 = 0, cnt = 0;
    // long long int n;
    cin >> s;
    // n = stoi(s);
    int a = s.length();
    if (a % 2 == 1)
    {
        cout << string((a + 1) / 2, '4') << string((a + 1) / 2, '7');
        // return 0;
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            if (s[i] == '4')
                cnt4++;
            else if (s[i] == '7')
                cnt7++;
            else
                break;
            if (cnt4 > a / 2)
            {
                cnt4--;
                break;
            }
            if (cnt7 > a / 2)
            {
                cnt7--;
                break;
            }
            cout << s[i];
        }

        cnt = cnt4 + cnt7;
        if (cnt < a)
        {

            if (s[cnt] > '7')
            {
                cout << string(a / 2 + 1 - cnt4, '4') << string(a / 2 + 1 - cnt7, '7');
            }
            else if (s[cnt] < '4')
            {
                cout << string(a / 2 - cnt4, '4') << string(a / 2 - cnt7, '7');
            }
            else
            {
                cout << '7' << string(a / 2 - cnt4, '4') << string(a / 2 - cnt7 - 1, '7');
            }
        }
    }
    return 0;
}