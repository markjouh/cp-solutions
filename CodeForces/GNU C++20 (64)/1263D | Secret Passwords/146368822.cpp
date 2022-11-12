#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
#define f first
#define s second
 
set<int> g[26];
bool has[26], seen[26];
 
void dfs(int u) {
    seen[u] = true;
    for (int v : g[u]) {
        if (!seen[v]) {
            dfs(v);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            has[c - 'a'] = true;
            for (char t : s) {
                g[c - 'a'].insert(t - 'a');
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (has[i] && !seen[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
}