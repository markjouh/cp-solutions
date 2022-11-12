#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
struct mergetree {
    int sz;
    vector<vector<pair<ll, ll>>> tree;
    vector<vector<ll>> pref;
 
    void init(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.resize(2 * sz);
    }
 
    void init_pref() {
        pref.resize(2 * sz);
        for (int i = 0; i < 2 * sz; i++) {
            pref[i].resize(tree[i].size());
            for (int j = 0; j < (int)tree[i].size(); j++) {
                pref[i][j] = tree[i][j].fi * tree[i][j].se;
                if (j > 0) {
                    pref[i][j] += pref[i][j - 1];
                }
            }
        }
    }
 
    void build(vector<vector<pair<ll, ll>>> &a, int x, int l, int r) {
        if (l + 1 == r) {
            if (l < (int)a.size()) {
                tree[x] = a[l];
            }
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        merge(all(tree[2 * x + 1]), all(tree[2 * x + 2]), back_inserter(tree[x]));
    }
 
    void build(vector<vector<pair<ll, ll>>> &a) {
        build(a, 0, 0, sz);
    }
 
    ll query(int L, int R, int vl, int vr, int x, int l, int r) {
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            // last element < vl
            int l1 = -1, r1 = tree[x].size();
            while (l1 + 1 < r1) {
                int mid = l1 + (r1 - l1) / 2;
                (tree[x][mid].fi < vl ? l1 : r1) = mid;
            }
 
            // last element < vr
            int l2 = -1, r2 = tree[x].size();
            while (l2 + 1 < r2) {
                int mid = l2 + (r2 - l2) / 2;
                (tree[x][mid].fi < vr ? l2 : r2) = mid;
            }
 
            return (l2 == -1 ? 0 : pref[x][l2]) - (l1 == -1 ? 0 : pref[x][l1]);
        }
        int mid = l + (r - l) / 2;
        return query(L, R, vl, vr, 2 * x + 1, l, mid) + query(L, R, vl, vr, 2 * x + 2, mid, r);
    }
 
    ll query(int l, int r, int vl, int vr) {
        return query(l, r, vl, vr, 0, 0, sz);
    }
};
 
const int N = 1001;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<pair<ll, ll>>> rect(N);
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            rect[h].push_back({w, h});
        }
        for (int i = 0; i < N; i++) {
            sort(all(rect[i]));
        }
        mergetree mt;
        mt.init(N);
        mt.build(rect);
        mt.init_pref();
 
        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            cout << mt.query(hs + 1, hb, ws + 1, wb) << '\n';
        }
    }
}