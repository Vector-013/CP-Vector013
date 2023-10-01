#include <iostream>
using namespace std;
int main()
{
    int arr[5][5] = {};
    int sum = 0;
    int x[] = {0, 1, 0, 0, -1}; // usage of two arrays as a "mover", 5 combinations of array x and y take in values of the location and 4 around it
    int y[] = {0, 0, 1, -1, 0};
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < 4; i++)
    { // could have done a simple traversal
        for (int j = 1; j < 4; j++)
        {

            for (int k = 0; k < 5; k++)
            {
                sum = sum + arr[i + x[k]][j + y[k]];
            }
            if (sum % 2 == 0)
                cout << 1; // initially all on
            else
                cout << 0;
            sum = 0;
        }
        cout << "\n";
    }
}