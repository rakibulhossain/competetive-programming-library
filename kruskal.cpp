#include<bits/stdc++.h>
using namespace std;
#define type int
const int siz=1e5+7;
struct node{
    int u,v;
    type w;
    bool operator<(const node& x)const{
        return w<x.w;
    }
};
vector<node>E;
int p[siz];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int kruskal()
{
    sort(E.begin(),E.end());
    int sz=E.size();
    type ans=0;
    for(int i=0;i<sz;i++)
    {
        if(find(E[i].u)!=find(E[i].v)){
            p[p[E[i].u]]= p[E[i].v];
            ans+=E[i].w;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
