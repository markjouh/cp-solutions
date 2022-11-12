#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second

constexpr int M = 1e9 + 7;

int madd(int a, int b) {
    return (a + b) % M;
}

int msub(int a, int b) {
    return (((a - b) % M) + M) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;

    // dp[i][j] = (permutation of size i)[last number is j'th largest] = ways
    vector<int> dp(n), new_dp(n);
    dp[0] = 1;

    // size of the current prefix
    for (int i = 1; i < n; i++) {
        vector<int> pref_dp(n + 1);
        for (int j = 0; j < n; j++) {
            pref_dp[j + 1] = madd(dp[j], pref_dp[j]);
        }
        // make the next character the j'th largest
        for (int j = 0; j < i + 1; j++) {
            if (s[i - 1] == '<') {
                // any rank [j + 1, j + 2, ..., i + 1) works.
                // for (int k = j; k < i; k++) {
                //     new_dp[j] = (new_dp[j] + dp[k]) % M;
                // }
                new_dp[j] = msub(pref_dp[i], pref_dp[j]);
            } else {
                // any rank [0, 1, ..., j) works.
                // for (int k = 0; k < j; k++) {
                //     new_dp[j] = (new_dp[j] + dp[k]) % M;
                // }
                new_dp[j] = pref_dp[j];
            }
        }
        dp = new_dp;
        fill(all(new_dp), 0);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = madd(ans, dp[i]);
    }
    cout << ans << '\n';
}