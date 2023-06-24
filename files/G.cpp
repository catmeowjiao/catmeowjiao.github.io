#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int n,a,b,u,v,w,k,s[100010],e[200010],ne[200010],we[200010];
bool flag;
map<int,bool> m;

void add(int a,int b,int w)
{
    e[++k] = b;
    ne[k] = s[a];
    we[k] = w;
    s[a] = k;
}

void dfs1(int r,int f,int x)
{
    for (int i = s[r]; i; i = ne[i]) {
        if (e[i] != f && e[i] != b) {
            m[x ^ we[i]] = true;
            dfs1(e[i],r,x ^ we[i]);
        }
    }
}

void dfs2(int r,int f,int x)
{
    for (int i = s[r]; i; i = ne[i]) {
        if (e[i] != f) {
            if(m[x ^ we[i]]) {
                flag = true;
                return ;
            }
            dfs2(e[i],r,x ^ we[i]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        memset(s,0,sizeof(s));
        k = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            add(u,v,w);
            add(v,u,w);
        }
        m.clear();
        m[0] = 1;
        dfs1(a,0,0);
        flag = false;
        dfs2(b,0,0);
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
