#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
int main()
{
    std::string s;
    std::cin >> s;
    int n = s.length();
    int cnt = 1, maxi = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            cnt = 1;
        else
        {
            cnt++;
            maxi = (maxi > cnt) ? maxi : cnt;
        }
    }
    printf("%d", maxi);
}