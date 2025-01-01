#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>

const int MOD = 998244353;

using namespace std;

long long calcProduct(const vector<int> &a, const vector<int> &b, const vector<int> &sortedA, const set<pair<int, int>> &sortedB)
{
    long long product = 1;
    auto bIt = sortedB.begin();
    int n = a.size();

    for (int i = 0; i < n; ++i)
    {
        product = (product * min(a[sortedA[i]], bIt->first)) % MOD;
        ++bIt;
    }

    return product;
}

void solve(vector<int> &a, vector<int> &b, int q, const vector<pair<int, int>> &queries)
{
    int n = a.size();

    // Create sorted indices for a
    vector<int> sortedA(n);
    iota(sortedA.begin(), sortedA.end(), 0); // Indices for a
    sort(sortedA.begin(), sortedA.end(), [&a](int i, int j)
         { return a[i] < a[j]; });

    // Create a multiset for b that stores pairs (value, index) so we can efficiently access b's elements
    set<pair<int, int>> sortedB;
    for (int i = 0; i < n; ++i)
    {
        sortedB.insert({b[i], i});
    }

    // Calculate initial product P
    long long P = calcProduct(a, b, sortedA, sortedB);
    cout << P << endl; // Output the initial product

    // Process each query
    for (const auto &query : queries)
    {
        int o = query.first, x = query.second - 1; // Convert to zero-based index

        // Remove the affected element from sortedB
        sortedB.erase({b[x], x});

        // Apply the modification (either to a or b)
        if (o == 1)
        {
            // Increase a[x] by 1
            a[x]++;
        }
        else
        {
            // Increase b[x] by 1
            b[x]++;
        }

        // Insert the modified value back into the sortedB set
        sortedB.insert({b[x], x});

        // Recalculate product P after the modification
        P = calcProduct(a, b, sortedA, sortedB);
        cout << P << endl; // Output the new product
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    solve(a, b, q, queries);

    return 0;
}
