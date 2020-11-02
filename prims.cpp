#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
const int inf=INT_MAX;
#define type int
struct node{
    int a,w;
    bool operator<(const node& x)const{
        return w>x.w;
    }
};
vector<node>cost[siz];
priority_queue<node>q;
int weight[siz];
bool vis[siz];
int n;
type prims(int s){
    for(int i=1;i<=n;i++) weight[i]=inf;
    weight[s]=0;
    q.push({s,0});
    type ans=0;
    while(!q.empty()){
        node u=q.top(); q.pop();
        if(vis[u.a]) continue;
        vis[u.a]=1;
        ans+=u.w;
        for(int i=0;i<cost[u.a].size();i++){
            node x=cost[u.a][i];
            if(!vis[x.a]&&weight[x.a]>x.w){
                weight[x.a]=x.w;
                q.push(x);
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}
