#include<bits/stdc++.h>
using namespace std;
#define type int
const int inf = 1000000000;
struct edge{
    int u,v;
    type f,c;
};
struct Dinic{
    int n,m=0,scaling;
    vector<vector<int> >graph;
    vector<edge>ed; // edges
    int s,t;
    vector<int>level,ptr; // ptr to next ptr in dfs
    Dinic(int n,int s,int t,int scaling): n(n),s(s),t(t),scaling(scaling){
        graph.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }
    void add_edge(int u,int v,type f){
        edge e;
        e.u=u,e.v=v,e.f=0,e.c=f;
        graph[u].push_back((int)ed.size());
        ed.push_back(e);
        e.u=v,e.v=u,e.f=e.c=f;
        graph[v].push_back((int)ed.size());
        ed.push_back(e);
        m+=2;
    }
    bool bfs(type lim){
        queue<int>q;
        q.push(s);
        for(int i=1;i<=n;i++) level[i]=inf;
        level[s]=0;
        while(!q.empty()&&level[t]==inf){
            int u=q.front();q.pop();
            for(int i=0;i<graph[u].size();i++){
                int id=graph[u][i];
                int v=ed[id].v;
                if(level[v]==inf&&ed[id].c-ed[id].f>=lim){
                    q.push(v);
                    level[v]=level[u]+1;
                }
            }
        }
        return level[t]!=inf;
    }
    int dfs(int x,type flow,type minf=INT_MAX){
        if(!flow) return 0;
        if(x==t) return flow;
        for(;ptr[x]<graph[x].size();ptr[x]++){
            int id=graph[x][ptr[x]];
            int v=ed[id].v;
            if(level[v]==level[x]+1&&ed[id].c-ed[id].f>=flow){
                type pushed=dfs(v,flow);
               // int pushed=dfs(v,flow,min(minf,ed[id].c-ed[id].f));
                if(pushed){
                    ed[id].f+=flow;
                    ed[id^1].f-=flow;
                    return flow;
                    //ed[id].f+=pushed;
                    // ed[id^1].f-=pushed;
                    // return pushed;
                }
            }
        }
        return 0;
    }
    type dinic(){
        type flow=0;
        for(type lim=(scaling)?(1<<30):1;lim>0;){
            if(!bfs(lim)){
                lim>>=1;
                continue;
            }
            for(int i=1;i<=n;i++) ptr[i]=0;
            int pushed;
            while(pushed=dfs(s,lim)){
                flow+=pushed;
            }
        }
        return flow;
    }
};
int main()
{

    return 0;
}
