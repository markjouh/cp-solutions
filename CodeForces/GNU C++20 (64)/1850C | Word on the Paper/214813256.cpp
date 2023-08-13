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
     vector<vector<char>> s(8, vector<char>(8));
     rep(i, 0, 8) rep(j, 0, 8) cin >> s[i][j];
     rep(i, 0, 8) {
         string res;
         rep(j, 0, 8) {
             if (s[j][i] != '.') {
                 res += s[j][i];
             }
         }
         if (!res.empty()) {
             cout << res << '\n';
             break;   
         }
     }
 }
}