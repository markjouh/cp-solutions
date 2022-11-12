#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
// intended solution (2d prefix sums, much better than mine)
 
const int N = 1001;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<ll>> pref(N, vector<ll>(N));
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            pref[h][w] += h * w;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            hb--; wb--;
 
            assert(hs >= 0 && hs < N); assert(ws >= 0 && ws < N); assert(hb >= 0 && hb < N); assert(wb >= 0 && wb < N);
            cout << pref[hb][wb] - pref[hb][ws] - pref[hs][wb] + pref[hs][ws] << '\n';
        }
    }
}