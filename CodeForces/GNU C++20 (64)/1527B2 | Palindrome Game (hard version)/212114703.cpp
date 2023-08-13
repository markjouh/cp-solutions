#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
#define VE vector
#define AR array
 
#define FOR(i, A, B) for (int i = A; i < B; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, A, B) for (int i = B - 1; i >= A; i--)
#define RF0R(i, N) RFOR(i, 0, N)
#define REP(N) F0R(_, N)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
void solve() {
    int N;
    string S;
    cin >> N >> S;
    int diff = 0, pairs = 0;
    F0R(i, N / 2) {
        if (S[i] != S[N - i - 1]) {
            diff++;
        }
        if (S[i] == '0' && S[N - i - 1] == '0') {
            pairs++;
        }
    }
    bool center = N % 2 && S[N / 2] == '0';
    if (diff == 0) {
        cout << (center && pairs > 0 ? "ALICE\n" : "BOB\n");
        return;
    }
    cout << (diff == 1 && pairs == 0 && center ? "DRAW\n" : "ALICE\n");
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: