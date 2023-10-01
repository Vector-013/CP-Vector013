#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    sort(s3.begin(), s3.end());
    string s = s1 + s2;
    sort(s.begin(), s.end());
    if (s != s3)
    {
        cout << "NO";
    }
    else
        cout << "YES";
}
