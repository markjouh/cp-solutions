#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
// I think this runs in ~O(30^2 N log(N))
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        vector<bool> take(30);
        for (int i = 29; i >= 0; i--) {
            take[i] = true;
            
            unordered_multiset<string> st;
            for (int j = 0; j < n; j++) {
                string s;
                for (int k = 0; k < 30; k++) {
                    if (take[k]) {
                        int p = 1 << k;
                        if (a[j] & p) {
                            s += '0';
                        } else {
                            s += '1';
                        }
                    }
                }
                st.insert(s);
            }
 
            for (int j = 0; j < n; j++) {
                string s;
                for (int k = 0; k < 30; k++) {
                    if (take[k]) {
                        int p = 1 << k;
                        if (b[j] & p) {
                            s += '1';
                        } else {
                            s += '0';
                        }
                    }
                }
                if (st.find(s) != st.end()) {
                    st.erase(st.find(s));
                } else {
                    take[i] = false;
                    break;
                }
            }
        }
 
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            int p = 1 << i;
            if (take[i]) {
                ans += p;
            }
        }
        cout << ans << '\n';
    }
}