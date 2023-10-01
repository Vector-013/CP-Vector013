#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n, s1 = 0, s2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s1 = 0;
        s2 = 0;

        for (int k = 0; k < 6; k++)
        { // int s1=0 ,s2=0; bad practice  variable declared multiple times
            string s3 = "3";
            s3.pop_back();
            s3.push_back(s[k]);

            if (k < 3)
                s1 = s1 + stoi(s3);
            if (k >= 3)
                s2 = s2 + stoi(s3);
        }
        if (s1 == s2)
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