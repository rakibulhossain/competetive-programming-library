#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
const int inf=INT_MAX;
struct node{
    int a,w;
    bool operator<(const node& x)const{
        return w>x.w;
    }
};
int nodes,edges,dis[siz];
vector<node>cost[siz];
void solve(int x)
{
    for(int i=1;i<=nodes;i++) dis[i]=inf;
    priority_queue<node>q;
    dis[x]=0;
    q.push({x,0});
    while(!q.empty()){
        node u=q.top(); q.pop();
        x=u.a;
        if(u.w!=dis[x]) continue;
        for(int i=0;i<cost[x].size();i++){
            if(dis[x]+cost[x][i].w<dis[cost[x][i].a]){
                dis[cost[x][i].a]=dis[x]+cost[x][i].w;
                q.push({cost[x][i].a,dis[cost[x][i].a]});
            }
        }
    }
}
int main()
{

    return 0;
}
