#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    long long p = *min_element(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] - p + 1 << '\n';
    }
}