// by ask
 
#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 
    long long T, L, R;
    cin >> T >> L >> R;
 
    vector<long long> DP(R + 1, 1e18);
    DP[1] = 0;
 
    for (long long i = 1; i < R; i++) {
        for (long long j = 2; (i * j) <= R; j++) {
            DP[i * j] = min(DP[i * j], DP[i] + (long long) i * ((j * (j - 1)) / 2));
        }
    }
 
    long long F = 0;
 
    for (int i = R; i >= L; i--) {
        F += (DP[i] % MOD);
        F *= (i != L ? T : 1);
        F %= MOD;
    }
 
    cout << (F % MOD) << "\n";
 return 0;
}