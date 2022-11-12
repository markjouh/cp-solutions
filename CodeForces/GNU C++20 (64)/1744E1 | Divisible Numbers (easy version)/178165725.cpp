#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
 
        ll ans1 = -1, ans2 = -1;
        // fix x for e1
        for (ll x = A+1; x <= C; x++) {
            ll g = gcd(A*B, x);
            ll req = A*B/g;
            ll y = B/req*req+req;
            if (y <= D) {
                ans1 = x;
                ans2 = y;
            }
        }
 
        cout << ans1 << ' ' << ans2 << '\n';
    }
}