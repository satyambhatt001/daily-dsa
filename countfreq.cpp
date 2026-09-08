#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;

    for (int x : a) {
        freq[x]++;
    }

    for (auto x : freq) {
        cout << x.first << " occurs " << x.second << " times" << endl;
    }

    return 0;
}
