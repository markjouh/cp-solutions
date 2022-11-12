#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define RNG(i, A, B) for (int i = A; i < (int)B; i++)
#define FOR(i, N) RNG(i, 0, N)

const int MOD = 1e9+7;

vector<vector<LL>> matmul(vector<vector<LL>> a, vector<vector<LL>> b) {
    assert(a[0].size() == b.size());
    int m = a.size(), n = a[0].size(), p = b[0].size();
    vector<vector<LL>> res(m, vector<LL>(p));
    FOR(i, m) {
        FOR(j, p) {
            FOR(k, n) {
                (res[i][j] += a[i][k]*b[k][j]) %= MOD;
            }
        }
    }
    return res;
}

vector<vector<LL>> matexp(vector<vector<LL>> base, LL exp) {
    vector<vector<LL>> res = base;
    exp--;
    while (exp) {
        if (exp%2 == 1) {
            res = matmul(res, base);
        }
        exp >>= 1;
        base = matmul(base, base);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N, K;
    cin >> N >> K;
    vector<vector<LL>> adj(N, vector<LL>(N));
    FOR(i, N) {
        FOR(j, N) {
            cin >> adj[i][j];
        }
    }
    adj = matexp(adj, K);
    LL ans = 0;
    FOR(i, N) {
        FOR(j, N) {
            (ans += adj[i][j]) %= MOD;
        }
    }
    cout << ans << '\n';
}
