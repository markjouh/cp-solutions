#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ((x + (int)1e9) % 2 == 0 ? e : o)++;
        }
 
        bool ok = false; 
        for (int i = 0; i <= (e + 1) / 2; i++) {
            int j = (n + 1) / 2 - i;
            if (j > (o + 1) / 2 || i + j != (n + 1) / 2) {
                continue;
            }
            if (j % 2 == 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "Alice\n" : "Bob\n");
    }
}