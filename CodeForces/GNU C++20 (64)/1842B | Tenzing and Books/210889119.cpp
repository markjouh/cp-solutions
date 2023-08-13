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
    int N, X;
    cin >> N >> X;
    VE<VE<int>> A(3, VE<int>(N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            if ((X | A[i][j]) == X) {
                res |= A[i][j];
            } else {
                break;
            }
        }
    }
    cout << (res == X ? "Yes\n" : "No\n");
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