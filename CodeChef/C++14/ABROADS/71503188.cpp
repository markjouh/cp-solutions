#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> sz, par;
vector<ll> pop, rpop;
multiset<ll> rpop_st;

// get the reigon of a town
int get_root(int u) {
    if (par[u] == -1) {
        return u;
    }
    return par[u] = get_root(par[u]);
}

// unite two reigons
void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
    rpop_st.erase(rpop_st.find(rpop[b]));
    rpop_st.erase(rpop_st.find(rpop[a]));
    rpop[a] += rpop[b];
    rpop_st.insert(rpop[a]);
}

// sets the population of an individual town & applies the difference to the reigon
void set_pop(int u, int x) {
    int d = x - pop[u];
    pop[u] = x;
    u = get_root(u);
    rpop_st.erase(rpop_st.find(rpop[u]));
    rpop[u] += d;
    rpop_st.insert(rpop[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    sz.resize(n, 1);
    pop.resize(n, 1);
    rpop.resize(n, 1);
    par.resize(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> pop[i];
        rpop[i] = pop[i];
        rpop_st.insert(pop[i]);
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[i] = {u, v};
    }
    vector<array<ll, 4>> q(k); // type, id, before, after
    for (int i = 0; i < k; i++) {
        char c;
        int id;
        cin >> c >> id;
        id--;
        if (c == 'D') {
            q[i] = {0, id};
        } else {
            int x;
            cin >> x;
            q[i] = {1, id, pop[id], x};
            set_pop(id, x);
        }
    }

    vector<bool> ok(m, true);
    for (int i = 0; i < k; i++) {
        if (q[i][0] == 0) {
            ok[q[i][1]] = false;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ok[i]) {
            // auto [u, v] = e[i];
            int u = e[i].first, v = e[i].second;
            unite(u, v);
        }
    }

    vector<ll> ans(k);
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = *rpop_st.rbegin();
        if (q[i][0] == 0) {
            // auto [u, v] = e[q[i][1]];
            int u = e[q[i][1]].first, v = e[q[i][1]].second;
            unite(u, v);
        } else {
            set_pop(q[i][1], q[i][2]);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }
}