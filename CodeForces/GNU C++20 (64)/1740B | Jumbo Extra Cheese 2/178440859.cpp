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
        int N;
        cin >> N;
        vector<ll> a(N);
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ll W, H;
            cin >> W >> H;
            ans += W*2+H*2;
            a[i] = max(W, H);
        }
        sort(all(a));
        for (int i = 0; i < N-1; i++) {
            ans -= a[i]*2;
        }
        cout << ans << '\n';
    }
}