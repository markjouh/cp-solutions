#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]].push_back(i + 1);
        }
        bool ok = true;
        for (auto [f, s] : mp) {
            ok &= s.size() >= 2;
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        for (auto [f, s] : mp) {
            int m = s.size();
            for (int i = 0; i < m; i++) {
                cout << s[(i + 1) % m] << ' ';
            }
        }
        cout << '\n';
    }
}