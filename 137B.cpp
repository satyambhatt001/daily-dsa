#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> used;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x >= 1 && x <= n) {
            used.insert(x);
        }
    }

    cout << n - used.size();
    return 0;
}
