#include <iostream>
#include <algorithm>
using namespace std;

int n,pos,cnt,d[200010];
pair<int,int> a[200010];

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1,a + n + 1);
    d[1] = a[1].second;
    cnt = 1;
    for (int i = 2;i <= n;i++)
    {
        if (a[i].second > d[cnt])
        {
            d[++cnt] = a[i].second;
        }
        else
        {
            pos = lower_bound(d + 1,d + cnt + 1,a[i].second) - d;
            d[pos] = a[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}