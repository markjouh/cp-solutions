#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        // for a given 1, adds 11, -1 if in the first position, -10 if in the last position
        int ans = count(s.begin(), s.end(), '1') * 11 - (s[0] == '1') - (s[n - 1] == '1') * 10;
        if (s.find('1') != string::npos) {
            int id = s.rfind('1');
            int d_bk = n - id - 1;
            if (id != n - 1 && d_bk <= k) {
                k -= d_bk;
                ans -= 10 - (id == 0);
                s[id] = '0';
                s[n - 1] = '1';
            }
            id = s.find('1');
            if (id != 0 && id != n - 1 && id <= k) {
                ans--;
            }
        }
        cout << ans << '\n';
    }
}