#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static vector<ll> shapes;

ll triangular(ll x) {
    return x * (x + 1) / 2;
}

void build() {
    const int LIM = 100000;
    shapes.resize(LIM);
    for (int i = 0; i < LIM; i++) {
        shapes[i] = 2LL * i + 3LL * triangular(i - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build();

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int res = 0;

        while (n > 1) {
            int pos = upper_bound(shapes.begin(), shapes.end(), n) - shapes.begin() - 1;
            if (pos < 0) break;
            n -= shapes[pos];
            res++;
        }

        cout << res << '\n';
    }
    return 0;
}
