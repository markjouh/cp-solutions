#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
     int n;
     ll c;
     cin >> n >> c;
     vi s(n);
     rep(i, 0, n) cin >> s[i];
     ll lo = 0, hi = 1e9;
     while (lo + 1 < hi) {
         ll mid = lo + (hi - lo) / 2;
         ll used = 0;
         bool ok = true;
         rep(i, 0, n) {
             used += (s[i] + 2 * mid) * (s[i] + 2 * mid);
             if (used > c) {
                 ok = false;
                 break;
             }
         }
         (ok ? lo : hi) = mid;
     }
     cout << lo << '\n';
 }
}