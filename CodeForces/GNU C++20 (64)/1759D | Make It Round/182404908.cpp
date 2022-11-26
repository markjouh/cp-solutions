#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        ll t = n;
        int fac2 = 0;
        while (t > 0 && t % 2 == 0) {
            t /= 2;
            fac2++;
        }
        int fac5 = 0;
        while (t > 0 && t % 5 == 0) {
            t /= 5;
            fac5++;
        }
        ll k = 1;
        while (k * 2 <= m && fac2 < fac5) {
            k *= 2;
            fac2++;
        }
        while (k * 5 <= m && fac5 < fac2) {
            k *= 5;
            fac5++;
        }
        while (k * 10 <= m) {
            k *= 10;
        }
        k = m / k * k;
        cout << n * k << '\n';
    }
}