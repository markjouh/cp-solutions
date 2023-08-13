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
 
void solve() {
    int N, K, X;
    cin >> N >> K >> X;
    if (X != 1) {
        cout << "YES\n";
        cout << N << '\n';
        REP(N) {
            cout << 1 << ' ';
        }
        cout << '\n';
    } else if (K >= 2 && N % 2 == 0) {
        cout << "YES\n";
        cout << N / 2 << '\n';
        REP(N / 2) {
            cout << 2 << ' ';
        }
        cout << '\n';
    } else if (K >= 3 && N > 1) {
        cout << "YES\n";
        cout << N / 2 << '\n';
        if (N % 2) {
            N -= 3;
            cout << 3 << ' ';
        }
        REP(N / 2) {
            cout << 2 << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
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