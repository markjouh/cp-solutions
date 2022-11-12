#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, sr, sc, d;
        cin >> n >> m >> sr >> sc >> d;
 
        if ((sr - d <= 1 && sc - d <= 1) || (sr + d >= n && sc + d >= m) || (sr - d <= 1 && sr + d >= n) || (sc - d <= 1 && sc + d >= m)) {
            cout << -1 << '\n';
            continue;
        }
 
 
 
        // We never have to go up or left, so n - 1 + m - 1 if reaching the destination is possible
        cout << n + m - 2 << '\n';
    }
}