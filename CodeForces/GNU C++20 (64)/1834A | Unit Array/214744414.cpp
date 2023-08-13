// just implementing an 800 to try an editor
 
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
  cin >> n;
  int pos = 0, neg = 0;
  rep(i, 0, n) {
   int x;
   cin >> x;
   (x == 1 ? pos : neg)++; 
  }
  int ans = 0;
  while (neg > pos) {
   neg--;
   pos++;
   ans++;
  }
  if (neg % 2) {
   neg--;
   pos++;
   ans++;
  }
  cout << ans << '\n';
 }
}