// mark zhou
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }
        cout << 0 << ' ';
        for (int i=1; i<n; i++) {
            int cur=0;
            for (int j=0; j<30; j++) {
                if (((a[i]>>j)&1) < ((a[i-1]>>j)&1)) {
                    cur+=pow(2, j);
                }
            }
            cout << cur << ' ';
            a[i]+=cur;
        }
        cout << '\n';
    }
}