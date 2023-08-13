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
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
     int cur = 1, ans = 1;
     rep(i, 1, n) {
         if (a[i] - a[i - 1] > k) {
             cur = 0;
         }
         cur++;
         ans = max(ans, cur);
     }
     cout << n - ans << '\n';
 }
}