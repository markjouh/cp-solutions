#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n * 2; i++) {
            int a;
            cin >> a;
            (a % 2 ? odd : even)++;
        }
        cout << (even == odd ? "YES" : "NO") << '\n';
    }
}