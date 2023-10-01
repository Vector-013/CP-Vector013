#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int ppl = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            ppl = ppl + arr[i];
        else if (arr[i] == -1)
        {
            if (ppl == 0)
                cnt++;
            else if (ppl > 0)
                ppl = ppl - 1;
        }
    }
    cout << cnt << "\n";
}