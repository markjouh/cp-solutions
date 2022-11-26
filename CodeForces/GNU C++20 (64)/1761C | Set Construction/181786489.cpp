#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c == '1') {
                    g[i].push_back(j);
                    in[j]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> o;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            o.push_back(u);
            for (int v : g[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<set<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i].insert(i + 1);
        }
        for (int u : o) {
            for (int v : g[u]) {
                for (int e : ans[u]) {
                    ans[v].insert(e);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << sz(ans[i]) << ' ';
            for (int e : ans[i]) {
                cout << e << ' ';
            }
            cout << '\n';
        }
    }
}