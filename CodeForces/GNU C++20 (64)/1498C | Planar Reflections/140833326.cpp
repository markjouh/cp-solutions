// mark zhou
#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        int ans=1+(k>1);
        vector<int> planes(n);
        planes[0]=1;
        for (int i=0; i<k-1; i++) {
            int pre=0;
            for (int j=0; j<n; j++) {
                int x=planes[j];
                planes[j]=pre;
                ans=(ans+pre)%M;
                pre=(pre+x)%M;
            }
            reverse(planes.begin(), planes.end());
        }
        cout << ans << '\n';
    }
}