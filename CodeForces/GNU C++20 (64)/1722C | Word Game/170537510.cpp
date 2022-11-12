#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<string>> a(3, vector<string>(n));
        map<string, int> mp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                mp[a[i][j]]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            int score = 0;
            for (int j = 0; j < n; j++) {
                if (mp[a[i][j]] == 1) {
                    score += 3;
                }
                if (mp[a[i][j]] == 2) {
                    score++;
                }
            }
            cout << score << ' ';
        }
        cout << '\n';
    }
}