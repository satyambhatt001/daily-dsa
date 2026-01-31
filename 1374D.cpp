#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    map<long long, long long> mp;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long r = x % k;
        if (r) mp[k - r]++;
    }

    if (mp.empty()) {
        cout << 0 << "\n";
        return;
    }

    long long ans = 0;
    for (auto &it : mp) {
        long long need = it.first;
        long long cnt = it.second;
        ans = max(ans, need + (cnt - 1) * k);
    }

    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
