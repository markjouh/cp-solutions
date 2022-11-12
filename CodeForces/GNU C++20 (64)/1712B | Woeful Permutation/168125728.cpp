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
        vector<int> ans(n);
        iota(all(ans), 1);
        for (int i = n - 1; i >= 1; i -= 2) {
            swap(ans[i], ans[i - 1]);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}