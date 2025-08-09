#include<bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        r++;
        int x = rng();
        a.emplace_back(l, x);
        a.emplace_back(r, x);
    }
    std::sort(a.begin(), a.end());
    
    int lst = -1;
    int cur = 0;
    
    std::vector<int> s {0};
    for (auto [i, x] : a) {
        if (i > lst) {
            s.emplace_back(cur);
        }
        lst = i;
        cur ^= x;
    }
    
    std::sort(s.begin(), s.end());
    int ans = std::unique(s.begin(), s.end()) - s.begin();
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}