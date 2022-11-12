#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        vector<set<char>> b(51);
        for (int i = 0; i < n; i++) {
            b[a[i]].insert(s[i]);
        }
        bool ok = true;
        for (int i = 1; i <= 50; i++) {
            ok &= int(b[i].size()) <= 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}