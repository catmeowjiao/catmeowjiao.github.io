#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,a[100010],d[100010][3];

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    memset(d,-0x3f,sizeof(d));
    d[0][0] = 0;
    for (int i = 1;i <= n;i++)
    {
        d[i][0] = max(d[i - 1][0],d[i - 1][2]);
        d[i][1] = max(d[i - 1][1],d[i - 1][0] - a[i]);
        d[i][2] = d[i - 1][1] + a[i];
    }
    cout << max(d[n][0],d[n][2]) << endl;
    return 0;
}