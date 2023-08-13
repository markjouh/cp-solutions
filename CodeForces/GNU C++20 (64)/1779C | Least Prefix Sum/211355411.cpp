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
    int N, M;
    cin >> N >> M;
    VE<LL> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    VE<LL> P = A;
    FOR(i, 1, N) {
        P[i] += P[i - 1];
    }
    priority_queue<int> pq;
    LL tot = 0;
    int ans = 0;
    RF0R(i, M) {
        while (P[i] + tot < P[M - 1]) {
            tot += 2 * pq.top();
            pq.pop();
            ans++;
        }
        if (A[i] > 0) {
            pq.push(A[i]);
        }
    }
    pq = {};
    tot = 0;
    FOR(i, M, N) {
        if (A[i] < 0) {
            pq.push(-A[i]);
        }
        while (P[i] + tot < P[M - 1]) {
            tot += 2 * pq.top();
            pq.pop();
            ans++;
        }
    }
    cout << ans << '\n';
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