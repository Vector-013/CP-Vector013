#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n, k, cnt = 0;
    cin >> n >> k;
    int arr[n];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            break;
        if (i <= k)
            cnt++;
        else
        {
            if (arr[i] >= arr[k])
                cnt++;
            else
                break;
        }
    }
    cout << cnt << "\n";
}