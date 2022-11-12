#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
vector<int> dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
 
        auto get = [&](int r, int c) {
            int res = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = r + i, nc = c + j;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '*') {
                        res++;
                    }
                }
            }
            return res;
        };
 
        vector<vector<bool>> cor(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '*') {
                    continue;
                }
                bool ok = get(i, j) == 3;
                vector<bool> used(4);
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int r = i + dr[k], c = j + dc[k];
                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '*') {
                        ok &= get(r, c) == 3;
                        ok &= !used[(k + 2) % 4];
                        used[k] = true;
                        cnt++;
                    }
                }
                ok &= cnt == 2;
                cor[i][j] = ok;
            }
        }
 
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '*' || cor[i][j]) {
                    continue;
                }
                bool cur = false;
                for (int k = 0; k < 4; k++) {
                    int r = i + dr[k], c = j + dc[k];
                    if (r >= 0 && r < n && c >= 0 && c < m) {
                        cur |= cor[r][c];
                    }
                }
                ok &= cur;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}