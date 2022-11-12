#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }
    cout << *max_element(all(dp[n - 1])) << '\n';
}