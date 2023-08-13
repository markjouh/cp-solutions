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
    string S;
    cin >> S;
    for (int i = 0; i < SZ(S); i++) {
        if (S[i] == '?') {
            if (i == 0) {
                S[i] = '0';
            } else {
                S[i] = S[i - 1];
            }
        }
    }
    cout << S << '\n';
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
 
// Minimize the number of 0s after 1s
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: