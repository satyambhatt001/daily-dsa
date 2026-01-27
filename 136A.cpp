#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n + 1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        p[x] = i;
    }

    for(int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }
    cout << '\n';
    return 0;
}
