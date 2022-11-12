#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<bool> inc(n);
        inc[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            inc[i] = inc[i + 1] && a[i] <= a[i + 1];
        }
        if (inc[0]) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        set<int> st;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
            if (cnt[a[i]] == 0) {
                ans++;
                st.erase(a[i]);
            } else {
                st.insert(a[i]);
            }
            if (st.empty() && (i == n - 1 || inc[i + 1])) {
                break;
            }
        }
        cout << ans << '\n';
    }
}