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
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
void solve() {
    int N;
    cin >> N;
    VE<int> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    sort(ALL(A));
    if (A[0] == 0 && A[N - 1] == 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int l = 0, r = N - 1, bal = 0;
    F0R(i, N) {
        if (bal >= 0) {
            cout << A[l] << ' ';
            bal += A[l];
            l++;
        } else {
            cout << A[r] << ' ';
            bal += A[r];
            r--;
        }
    }
    cout << '\n';
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