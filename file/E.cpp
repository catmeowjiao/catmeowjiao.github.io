#include <iostream>
#include <algorithm>
using namespace std;

int a[200010],f[200010],b[200010];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = f[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            b[i] = b[i + 1] + !a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                ans += b[i];
            }
        }
        long long tmp = ans;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                ans = max(ans,tmp - b[i] + f[i - 1]);
            } else {
                ans = max(ans,tmp - f[i] + b[i + 1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
