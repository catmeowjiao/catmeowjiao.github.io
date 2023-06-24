#include <iostream>
using namespace std;

int a[200010];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0x3f3f3f3f;
        a[n + 1] = 0x3f3f3f3f;
        bool flag = false,ans = true;
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (a[i] == a[j + 1] && j <= n) {
                j++;
            }
            if (a[i - 1] > a[i] && a[j] < a[j + 1]) {
                if (flag) {
                    ans = false;
                } else {
                    flag = true;
                }
            }
            i = j;
        }
        if (flag && ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
