#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> present(1001, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            present[x] = 1;
        }

        int ans = -1;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            if(ans == -1 && present[x]){
                ans = x;
            }
        }

        if(ans == -1){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            cout << 1 << ' ' << ans << '\n';
        }
    }
