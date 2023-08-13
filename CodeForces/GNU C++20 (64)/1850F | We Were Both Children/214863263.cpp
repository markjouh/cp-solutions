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
     vi cnt(n+1);
     rep(i, 0, n) {
         int x;
         cin >> x;
         if (x <= n) {
             cnt[x]++;
         }
     }
     vi trap(n+1);
     rep(i, 1, n+1) {
         if (cnt[i] == 0) continue;
         for (int j = i; j <= n; j += i) {
             trap[j] += cnt[i];
         }
     }
     cout << *max_element(all(trap)) << '\n';
 }
}