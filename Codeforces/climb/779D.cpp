// void solve(){
// 	vector<int> comp;
// 	int L,n; cin>>L>>n;
// 	 for(int i=0;i<=n;i++) {
// 		int x; cin>>x; comp.push_back(x);
// 	}sort(all(comp));
// 	int l=0,r=n;
// 	while(l<=r){
// 		int m=(l+r)/2;
// 		vector<int> v;
// 		for(int i=0;i<=n;i++){
// 			int k=comp[m]^i;
// 			v.push_back(k);
// 		}
// 		sort(all(v));
// 		if(v==comp){
// 			cout<<comp[m]<<"\n"; return;
// 		}else{
// 			if(v<comp) l=m+1;else r=m-1;
// 		}
// 	}
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int q, n;
    cin >> q >> n;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int l = 0, r = n;

    while (l <= r)
    {
        int m = (l + r) / 2;
        vector<int> z(n + 1);
        for (int i = 0; i <= n; i++)
            z[i] = v[m] ^ i;
        sort(z.begin(), z.end());
        if (z != v)
        {
            if (z < v)
                l = m + 1;
            else
                r = m - 1;
        }
        else
        {
            cout << v[m] << '\n';
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}