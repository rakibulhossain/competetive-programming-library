#include<bits/stdc++.h>
using namespace std;
#define type int
#define Maxx 1001
const int inf=100000;
struct edge{
    int u,v;
    type w;
};
vector<edge>v;
type dis[Maxx];
int n,m;
bool bellmanford(int s){
    // s is the source
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    // will update shortest distances at most level n-1
    for(int i=1;i<n;i++){
        bool f=false;
        for(int j=0;j<m;j++){
            int x=v[j].u;
            int y=v[j].v;
            int z=v[j].w;
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                f=true;
            }
        }
        if(!f) return false;
    }
    // if it updates nth time then it must have a negative cycle
    for(int j=0; j<m; j++){
        int x=v[j].u;
        int y=v[j].v;
        int z=v[j].w;
        if(dis[y]>dis[x]+z) return true;
    }
    return false;
}
int main()
{

    return 0;
}
