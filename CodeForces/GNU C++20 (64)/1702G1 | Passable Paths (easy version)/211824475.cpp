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
    int N;
    cin >> N;
    VE<VE<int>> G(N);
    REP(N - 1) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    int Q;
    cin >> Q;
    REP(Q) {
        int K;
        cin >> K;
        VE<int> P(K);
        F0R(i, K) {
            cin >> P[i];
            P[i]--;
        }
        VE<int> dist(N, 1e9);
        dist[P[0]] = 0;
        queue<int> q;
        q.push(P[0]);
        while (SZ(q)) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int end1 = P[0];
        F0R(i, K) {
            if (dist[P[i]] > dist[end1]) {
                end1 = P[i];
            }
        }
        fill(ALL(dist), 1e9);
        dist[end1] = 0;
        q = {};
        q.push(end1);
        VE<int> from(N, -1);
        while (SZ(q)) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    from[v] = u;
                    q.push(v);
                }
            }
        }
        int end2 = P[0];
        F0R(i, K) {
            if (dist[P[i]] > dist[end2]) {
                end2 = P[i];
            }
        }
        int u = end2;
        VE<bool> cont(N);
        while (u != -1) {
            cont[u] = true;
            u = from[u];
        }
        bool ok = true;
        F0R(i, K) {
            ok &= cont[P[i]];
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
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