#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define siz 1000
#define type int
int edges,u,v,n=6;
type rgraph[siz][siz], graph[siz][siz],parent[siz],flow;
bool bfs(int s,int t){
    bool vis[siz];
    memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(s);
    parent[s]=-1; vis[s]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=1; i<=n; i++){
            if(!vis[i]&&rgraph[u][i]){
                vis[i]=true;
                parent[i]=u;
                q.push(i);
                if(i==t) break;
            }
        }
        if(vis[t]) break;
    }
    return (vis[t]==true);

}
type getmaxflow(int s,int t){
    type max_flow=0;
    //creating residual graph
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            rgraph[i][j]=graph[i][j];
    // while no augment path found
    // can use dfs or bfs or disjktra in path finding section as required
    while(bfs(s,t)){
        type path_cap=INT_MAX;
        for(int i=t; i!=s; i=parent[i]){
            int j=parent[i];
            path_cap=min(path_cap,rgraph[j][i]); // parent to child

        }
        for(int i=t; i!=s; i=parent[i]){
            int j=parent[i];
            rgraph[j][i]-=path_cap; // parent to child
            rgraph[i][j]+=path_cap; // child to parent
        }

        max_flow+=path_cap;
    }
    return max_flow;
}
int main()
{
    cout<<getmaxflow(1,6)<<endl;
    return 0;
}
