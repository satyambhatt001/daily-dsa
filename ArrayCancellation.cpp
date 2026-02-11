#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long balance = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        balance += x;
      
        if (balance < 0) {
            balance = 0;
        }
    }
    
    
    cout << balance << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
