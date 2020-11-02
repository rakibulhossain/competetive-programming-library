#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
int arr[siz];
struct info
{
    int prop,sum;
}tree[4*siz];
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b]; tree[node].prop=0;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    init(left,b,mid); init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum; tree[node].prop=0;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b) return;
    else if(b>=i&&e<=j){
        tree[node].sum+=(((e-b)+1)*x); tree[node].prop+=x;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    update(left,b,mid,i,j,x); update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(((e-b)+1)*tree[node].prop);
}
int query(int node,int b,int e,int i,int j,int x=0)
{
    if(i>e||j<b) return 0;
    else if(b>=i&&e<=j) return tree[node].sum+(((e-b)+1)*x);
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    int a=query(left,b,mid,i,j,x+tree[node].prop);
    int b1=query(right,mid+1,e,i,j,x+tree[node].prop);
    return a+b1;
}
int main()
{
    return 0;
}

