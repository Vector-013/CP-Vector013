#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 1; i < n; i++) {
        p[i] = std::max(p[i], p[i - 1]);
    }
    std::vector<bool> bad(n);
    for (int i = 1; i < n; i++) {
        if (p[i - 1] != i) {
            bad[i] = true;
        }
    }
    
    std::string s;
    std::cin >> s;
    
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (bad[i] && s.substr(i - 1, 2) == "LR") {
            cnt++;
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        x--;
        if (bad[x] && s.substr(x - 1, 2) == "LR") {
            cnt--;
        }
        if (bad[x + 1] && s.substr(x, 2) == "LR") {
            cnt--;
        }
        if (s[x] == 'L') {
            s[x] = 'R';
        } else {
            s[x] = 'L';
        }
        if (bad[x] && s.substr(x - 1, 2) == "LR") {
            cnt++;
        }
        if (bad[x + 1] && s.substr(x, 2) == "LR") {
            cnt++;
        }
        if (cnt == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}
