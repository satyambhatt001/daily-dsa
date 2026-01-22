#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> res;

        if (n >= k && (n - k) % 2 == 0) {
            for (int i = 0; i < k - 1; i++) {
                res.push_back(1);
            }
            res.push_back(n - (k - 1));
        } 
        else if (n >= 2 * k && n % 2 == 0) {
            for (int i = 0; i < k - 1; i++) {
                res.push_back(2);
            }
            res.push_back(n - 2 * (k - 1));
        } 
        else {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (long long x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
