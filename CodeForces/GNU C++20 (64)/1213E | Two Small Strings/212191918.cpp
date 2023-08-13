#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
using LL = long long;
using PII = pair<int, int>;
template<class T> using VE = vector<T>;
template<class T, size_t SZ> using AR = array<T, SZ>;
 
#define FOR(i, A, B) for (int i = A; i < B; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, A, B) for (int i = B - 1; i >= A; i--)
#define RF0R(i, N) RFOR(i, 0, N)
#define REP(N) F0R(_, N)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
template<typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
void solve() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    string s = "abc";
    do {
        AR<string, 3> ans;
        F0R(i, 3) {
            REP(N) {
                ans[0] += s[i];
            }
        }
        REP(N) {
            ans[1] += s[0];
        }
        REP(N) {
            ans[1] += s[1];
            ans[1] += s[2];
        }
        REP(N) {
            ans[2] += s[0];
            ans[2] += s[1];
        }
        REP(N) {
            ans[2] += s[2];
        }
        F0R(i, 3) {
            if (ans[i].find(A) == string::npos && ans[i].find(B) == string::npos) {
                cout << "YES\n";
                cout << ans[i] << '\n';
                return;
            }
        }
    } while (next_permutation(ALL(s)));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: