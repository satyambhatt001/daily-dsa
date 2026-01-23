#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        if (b % a != 0) {
            cout << -1 << '\n';
            continue;
        }

        ll x = b / a;
        int moves = 0;

        while (x % 8 == 0) {
            x /= 8;
            moves++;
        }
        while (x % 4 == 0) {
            x /= 4;
            moves++;
        }
        while (x % 2 == 0) {
            x /= 2;
            moves++;
        }

        if (x == 1) cout << moves << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
