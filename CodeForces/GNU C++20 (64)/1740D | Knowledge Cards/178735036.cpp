#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k + 1);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            a[x] = i;
        }
        oset<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }
        bool ok = true;
        for (int i = k; i >= 1; i--) {
            int less = st.order_of_key(a[i]);
            if (n * m - less - 4 < 0) {
                ok = false;
                break;
            }
            st.erase(st.find(a[i]));
        }
        cout << (ok ? "YA\n" : "TIDAK\n");
    }
}