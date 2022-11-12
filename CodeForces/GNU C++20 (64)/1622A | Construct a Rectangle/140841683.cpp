// mark zhou
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> a(3);
        for (int &x : a) {
            cin >> x;
        }
        bool ok = false;
        ok |= a[0]==a[1] && a[2]%2==0;
        ok |= a[0]==a[2] && a[1]%2==0;
        ok |= a[1]==a[2] && a[0]%2==0;
        ok |= a[0]==a[1]+a[2];
        ok |= a[1]==a[0]+a[2];
        ok |= a[2]==a[0]+a[1];
        cout << (ok ? "YES" : "NO") << '\n';
    }
}