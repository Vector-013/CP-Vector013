#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t, n, totsum, countneg;
    long long int maxneg, minpos;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        int arr[n];
        totsum = 0;
        countneg = 0;
        maxneg = -1e10;
        minpos = 1e10;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            totsum += abs(arr[i]);
            if (arr[i] < 0)
            {
                countneg++;
                if (arr[i] > maxneg)
                {
                    maxneg = arr[i];
                }
            }

            if (arr[i] < minpos && arr[i] >= 0)
            {
                minpos = arr[i];
            }
        }
        if (countneg % 2 == 1 && abs(maxneg) > minpos)
        {
            totsum -= 2 * minpos;
        }
        else if (countneg % 2 == 1 && abs(maxneg) <= minpos)
        {
            totsum += 2 * (maxneg);
        }
        cout << totsum << endl;
    }
}