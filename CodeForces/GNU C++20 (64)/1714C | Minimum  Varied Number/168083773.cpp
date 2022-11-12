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
    vector<string> ans(46, string(9, '9'));
    for (int i = 0; i < (1 << 9); i++) {
        int sum = 0;
        string cur;
        for (int j = 1, k = 1; j < (1 << 9); j *= 2, k++) {
            if (i & j) {
                sum += k;
                cur += '0' + k;
            }
        }
        if (sz(cur) < sz(ans[sum]) || (sz(cur) == sz(ans[sum]) && cur < ans[sum])) {
            ans[sum] = cur;
        }
    }
    while (tc--) {
        int s;
        cin >> s;
        cout << ans[s] << '\n';
    }
}