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
 
int tree_sz;
VE<int> tree;
 
void build(VE<int> &a, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl + 1 == tr) {
        if (tl < SZ(a)) {
            tree[x] = a[tl];
        }
        return;
    }
    int mid = tl + (tr - tl) / 2;
    build(a, 2 * x + 1, tl, mid);
    build(a, 2 * x + 2, mid, tr);
    tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
}
 
int query(int l, int r, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl >= r || tr <= l) {
        return -1e9;
    }
    if (tl >= l && tr <= r) {
        return tree[x];
    }
    int mid = tl + (tr - tl) / 2;
    return max(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
}
 
void solve() {
    int N;
    cin >> N;
    VE<int> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    VE<int> B(N);
    F0R(i, N) {
        cin >> B[i];
    }
    int M;
    cin >> M;
    VE<int> X(M);
    F0R(i, M) {
        cin >> X[i];
    }
    F0R(i, N) {
        if (A[i] < B[i]) {
            cout << "NO\n";
            return;
        }
    }
    VE<int> unq = A;
    unq.insert(unq.end(), ALL(B));
    unq.insert(unq.end(), ALL(X));
    sort(ALL(unq));
    unq.resize(unique(ALL(unq)) - unq.begin());
    F0R(i, N) {
        A[i] = lower_bound(ALL(unq), A[i]) - unq.begin();
        B[i] = lower_bound(ALL(unq), B[i]) - unq.begin();
    }
    VE<VE<int>> to_cut(SZ(unq));
    F0R(i, N) {
        if (A[i] > B[i]) {
            to_cut[B[i]].push_back(i);
        }
    }
    VE<int> razors(SZ(unq));
    F0R(i, M) {
        razors[lower_bound(ALL(unq), X[i]) - unq.begin()]++;
    }
    tree_sz = 1;
    while (tree_sz < N) {
        tree_sz *= 2;
    }
    tree.resize(2 * tree_sz, -1e9);
    build(B);
    bool ok = true;
    F0R(i, SZ(to_cut)) {
        if (SZ(to_cut[i]) == 0) {
            continue;
        }
        int segs = 1;
        F0R(j, SZ(to_cut[i]) - 1) {
            if (query(to_cut[i][j], to_cut[i][j + 1]) > i) {
                segs++;
            }
        }
        ok &= segs <= razors[i];
    }
    cout << (ok ? "YES\n" : "NO\n");
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