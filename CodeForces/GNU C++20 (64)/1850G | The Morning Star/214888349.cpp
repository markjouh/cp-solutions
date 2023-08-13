#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
// find the X from 1 to n that is divisible by as many a[i] as possible
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
     int n;
     cin >> n;
     map<int, int> st_x, st_y, xmy, xpy;
     ll ans = 0;
     rep(i, 0, n) {
         int x, y;
         cin >> x >> y;
         ans += st_x[x]++;
         ans += st_y[y]++;
         ans += xmy[x-y]++;
         ans += xpy[x+y]++;
     }
     cout << ans*2 << '\n';
 }
}