#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        while (!s.empty() && s.back() == ')') {
            s.pop_back();
        }
        cout << (s.size() * 2 < n ? "Yes\n" : "No\n");
    }
}