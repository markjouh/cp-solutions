#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
void solve() {
    int N;
    string S;
    cin >> N >> S;
    int bal = 0;
    bool nn = true, np = true;
    for (int i = 0; i < N; i++) {
        bal += (S[i] == '(' ? 1 : -1);
        nn &= bal >= 0;
        np &= bal <= 0;
    }
    if (bal != 0) {
        cout << -1 << '\n';
        return;
    }
    if (nn || np) {
        cout << 1 << '\n';
        for (int i = 0; i < N; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << 2 << '\n';
    VE<int> op, cl;
    for (int i = N - 1; i >= 0; i--) {
        (S[i] == '(' ? op : cl).push_back(i);
    }
    VE<int> ans(N, 2);
    while (SZ(op) && SZ(cl)) {
        while (SZ(cl) && cl.back() < op.back()) {
            cl.pop_back();
        }
        if (SZ(cl)) {
            ans[op.back()] = 1;
            op.pop_back();
            ans[cl.back()] = 1;
            cl.pop_back();
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
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
 
// If the number of opening and closing parentheses aren't equal, obviously there is no answer
// Otherwise, there is always an answer: color the first opening the same as the first closing, etc.
 
// I feel like 2 is always enough
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: