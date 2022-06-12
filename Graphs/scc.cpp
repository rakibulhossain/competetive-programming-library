#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
stack<int>s;
bool vis[siz];
int n;
vector<int>v[siz],uv[siz],com[siz];
void dfs(int x){
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]) dfs(v[x][i]);
    s.push(x);
}
void dfs2(int x,int mark){
    com[mark].push_back(x);
    vis[x]=true;
    for(int i=0;i<uv[x].size();i++)
        if(!vis[uv[x][i]]) dfs2(uv[x][i],mark);
}
void findscc(){
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    memset(vis,0,sizeof(vis));
    int mark=0;
    while(!s.empty()){
        int u=s.top(); s.pop();
        if(!vis[u]) dfs2(u,++mark);
    }
}
int main()
{

    return 0;
}
