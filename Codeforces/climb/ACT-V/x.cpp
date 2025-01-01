bool can(int am)
{
    int C = 0;
    for (int i = 1; i <= 200000; i++)
    {
        C += cnt[i] / am;
    }
    return (C >= k);
}

int main()
{
    //	freopen("apache.in","r",stdin);
    //	freopen("apache.out","w",stdout);
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        cnt[ar[i]]++;
    }

    int l, r;
    l = 1;
    r = n;
    while (l < r)
    {
        int mid = l + r + 1;
        mid /= 2;
        if (can(mid))
            l = mid;
        else
            r = mid - 1;
    }

    for (int i = 1; i <= 200000; i++)
    {
        for (int j = 1; j <= cnt[i] / r; j++)
        {
            if (ans.size() < k)
                ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;

    //	cin.get(); cin.get();
    return 0;
}