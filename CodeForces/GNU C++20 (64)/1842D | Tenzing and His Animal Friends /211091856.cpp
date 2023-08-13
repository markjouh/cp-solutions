#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
void solve() {
    int N, M;
    cin >> N >> M;
    VE<VE<PII>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    VE<LL> d(N, 1e18);
    d[N - 1] = 0;
    set<PII> q;
    q.insert({0, N - 1});
    while (SZ(q)) {
        int u = q.begin() -> S;
        q.erase(q.begin());
        for (auto [v, w] : G[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.insert({d[v], v});
            }
        }
    }
    if (d[0] == 1e18) {
        cout << "inf\n";
        return;
    }
    VE<LL> unq = d;
    sort(ALL(unq));
    unq.resize(unique(ALL(unq)) - unq.begin());
    while (unq.back() > d[0]) {
        unq.pop_back();
    }
    cout << d[0] << ' ' << SZ(unq) - 1 << '\n';
    for (int i = 1; i < SZ(unq); i++) {
        for (int j = 0; j < N; j++) {
            cout << (d[j] >= unq[i]);
        }
        cout << ' ' << unq[i] - unq[i - 1] << '\n';
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
 
// If 1 isn't in the same component as N, we can play games with all of 1's component endlessly
// Otherwise, the game lasts for a finite amount of time, as vertices connected to N have limited time
 
// Let T be the maximum play time vertex 1 can get (equal to the shortest path from N to 1)
// Since all games must include 1, it's not possible for us to spend more than T time playing games.
 
// We can always spend T time playing games using the following construction:
// Let max_t[v] for all vertices v be min(dist(v, N), T)
// 1. Play a game for time min(max_t) with all vertices and subtract this value from all max_t
// 2. Forget about all vertices with max_t == 0
// Repeat 1 and 2 until no vertices remain.
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: