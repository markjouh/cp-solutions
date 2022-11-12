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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool done = false;
        vector<int> cnt(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            if (++cnt[a[i]] == 2) {
                cout << i + 1 << '\n';
                done = true;
                break;
            }
        }
        if (!done) {
            cout << 0 << '\n';
        }
    }
}