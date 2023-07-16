#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,a[100010],d[100010][2];

int main()
{
    cin >> n;
    for  (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    memset(d,-0x3f,sizeof(d));
    d[0][0] = 0;
    for (int i = 1;i <= n;i++)
    {
        d[i][0] = max(d[i - 1][0],d[i - 1][1] + a[i]);
        d[i][1] = max(d[i - 1][1],d[i - 1][0] - a[i]);
    }
    cout << d[n][0] << endl;
    return 0;
}