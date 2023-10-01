#include <iostream>
#include <string>
#include <vector>
using namespace std;
int find_char(string k, char a)
{
    for (int i = 0; i < k.length(); i++)
    {
        if (a == k[i])
        {
            return i + 1;
        }
    }
}
int main()
{
    int t, pos = 0, oldpos, time = 0;
    string k, s;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> k >> s;
        pos = find_char(k, s[0]);
        for (int j = 1; j < s.length(); j++)
        {
            oldpos = pos;
            pos = find_char(k, s[j]);
            time = time + abs(pos - oldpos);
        }
        cout << time << "\n";
        time = 0;
    }
}