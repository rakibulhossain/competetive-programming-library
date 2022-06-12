#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
int block;
struct query{
    int l,r,in;
    bool operator<(const query& x)const{
        if(l/block!=x.l/block) return l/block<x.l/block;
        return r<x.r;
    }
}q[siz];
void solve(int* a,int n,int q1,int* ans)
{
    // n = array size q1 = query size
    block=sqrt(n);
    sort(q,q+q1);
    int currl=0,currr=0,sum=0;
    for(int i=0;i<q1;i++)
    {
        int l=q[i].l,r=q[i].r;
        while(currl>l){
            sum+=a[currl-1]; currl--;
        }
        while(currr<=r){
            sum+=a[currr]; currr++;
        }
        while(currl<l){
            sum-=a[currl]; currl++;
        }
        while(currr>r+1){
            sum-=a[currr-1]; currr--;
        }
        ans[q[i].in]= sum;
    }

}
int main()
{

    return 0;
}
