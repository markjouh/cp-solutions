#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
#define VE vector
#define AR array
 
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
 
// For each suffix, store the next occurrence of each digit starting from i
 
void solve() {
    string S;
    int M;
    string L, R;
    cin >> S >> M >> L >> R;
    int N = SZ(S);
    VE<int> db(N);
    F0R(i, N) {
        db[i] = S[i] - '0';
    }
    VE<int> lo(M), hi(M);
    F0R(i, M) {
        lo[i] = L[i] - '0';
        hi[i] = R[i] - '0';
    }
    int pos = -1;
    F0R(i, M) {
        VE<bool> vis(10);
        int tot = 0;
        while (pos < N && tot < hi[i] - lo[i] + 1) {
            pos++;
            if (db[pos] >= lo[i] && db[pos] <= hi[i] && !vis[db[pos]]) {
                vis[db[pos]] = true;
                tot++;
            }
        }
    }   
    // cout << pos << ' ' << N << '\n';
    cout << (pos == N ? "YES\n" : "NO\n");
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: