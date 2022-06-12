#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
// t = 1st parent; l = level , par = ancestors
int n,t[siz],l[siz],par[siz][20];
vector<int>v[siz];
void dfs(int x,int from,int level=0)
{
    l[x]=level;
    t[x]=from;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=from) dfs(v[x][i],x,level+1);
}
void lca_init()
{
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++) par[i][0]=t[i];
    for(int j=1;(1<<j)<n;j++)
        for(int i=1;i<=n;i++)
            if(par[i][j-1]!=-1) par[i][j]=par[par[i][j-1]][j-1];
}
int lca(int p,int q)
{
    if(l[p]<l[q]) swap(p,q);
    int log=31-__builtin_clz(l[p]);
    for(int i=log;i>=0;i--)
    {
        if(l[p]-(1<<i)>=l[q]) p=par[p][i];
    }
    if(p==q) return p;
    for(int i=log;i>=0;i--)
    {
        if(par[p][i]!=-1&&par[p][i]!=par[q][i])
            p=par[p][i],q=par[q][i];
    }
    return t[p];
}
int main()
{

    return 0;
}
