#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
 
const int INF = 1e5;
 
struct Rect {
    int x1, y1, x2, y2;
};
 
Rect GetIntersection(Rect a, Rect b) {
    return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Rect res = {-INF, -INF, INF, INF};
        for (int i = 0; i < n; i++) {
            int x, y;
            bool left, up, right, down;
            cin >> x >> y >> left >> up >> right >> down;
            Rect cur = {x, y, x, y};
            if (left) {
                cur.x1 = -INF;
            }
            if (up) {
                cur.y2 = INF;
            }
            if (right) {
                cur.x2 = INF;
            }
            if (down) {
                cur.y1 = -INF;
            }
            res = GetIntersection(res, cur);
        }
        if (res.x1 <= res.x2 && res.y1 <= res.y2) {
            cout << 1 << ' ' << res.x1 << ' ' << res.y1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}