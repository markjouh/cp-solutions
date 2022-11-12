#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
 
        vector<int> d(n);
 
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                ans += i;
                d[i] = max(d[i], (n - i - 1) - i);
            }
            if (s[i] == 'R') {
                ans += n - i - 1;
                d[i] = max(d[i], i - (n - i - 1));
            }
        }
 
        sort(all(d), greater<int>());
        for (int i = 0; i < n; i++) {
            ans += d[i];
            cout << ans << ' ';
        }
        cout << '\n';
    }
}