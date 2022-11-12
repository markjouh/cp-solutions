#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
/*
A shortest path between two vertices is always in one of these two forms:
 
min(a[u], a[v])
 
min_all_a * 2
 
If there is one edge, it can only be between u and v, so the distance would be min(a[u], a[v]).
If there are two edges, one can go from u to mn, and another from mn to v.
A shortest path never needs to contain more than 2 edges, as each edge has weight at least mn,
so a path of length >= 3 will always have distance >= mn * 3.
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 1, r = 1e9 + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            vector<int> b = a;
            int cost1 = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] * 2 < mid) {
                    cost1++;
                    b[i] = 1e9;
                }
            }
            int cost2 = 2;
            for (int i = 0; i < n - 1; i++) {
                if (b[i] >= mid || b[i + 1] >= mid) {
                    cost2 = 1;
                }
                if (b[i] >= mid && b[i + 1] >= mid) {
                    cost2 = 0;
                    break;
                }
            }
            (cost1 + cost2 <= k ? l : r) = mid;
        }
        cout << l << '\n';
    }
}