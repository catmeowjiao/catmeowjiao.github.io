#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k,ans,a[100010],d[100010][110][2];

int main()
{
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    memset(d,-0x3f,sizeof(d));
    d[0][0][0] = 0;
    for (int i = 1;i <= n;i++)
    {
        d[i][0][0] = 0;
        for (int j = 1;j <= k;j++)
        {
            d[i][j][0] = max(d[i - 1][j][0],d[i - 1][j][1] + a[i]);
            d[i][j][1] = max(d[i - 1][j][1],d[i - 1][j - 1][0] - a[i]);
        }
    }
    for (int i = 0;i <= k;i++)
    {
        ans = max(ans,d[n][i][0]);
    }
    cout << ans << endl;
    return 0;
}