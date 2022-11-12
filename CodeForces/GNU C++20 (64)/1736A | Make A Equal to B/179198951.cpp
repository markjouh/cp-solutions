#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
 
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
        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            ans1 += a[i] != b[i];
        }
        int ans2 = abs(count(all(a), 1) - count(all(b), 1)) + 1;
        cout << min(ans1, ans2) << '\n';
    }
}