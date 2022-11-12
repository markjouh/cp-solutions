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
        vector<int> cnt(2);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % 2]++;
        }
        cout << min(cnt[0], cnt[1]) << '\n';  
    }
}