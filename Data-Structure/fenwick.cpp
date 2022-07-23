#include<bits/stdc++.h>
using namespace std;
#define type int
const int siz=2e5+7;

// 0 based indexing query idx=(idx & (idx+1))-1 amd update idx = (idx | (idx+1) )
// 1 based indexing query idx-=(idx & -idx) and update idx+=(idx & -idx)
// complexity O(logn) per query and update and space complexity O(n)
type bit1[siz],bit2[siz];
type get(type *bit,int idx)
{
    type ret = 0;
    for(int i=idx; i>=0; i=(i&(i+1))-1) ret+=bit[i];
    return ret;
}
void updt(type *bit,int idx,int val)
{
    for(int i=idx;i<siz;i|=i+1) bit[i]+=val;
}

void range_updt(int l,int r,int val)
{
    updt(bit1,l,val);
    updt(bit1,r+1,-val);
    updt(bit2,l,val*(l-1));
    updt(bit2,r+1,-val*r);
}
type gt(int idx)
{
    return get(bit1,idx)*idx-get(bit2,idx);
}
type query(int l,int r)
{
    return gt(r)-gt(l-1);
}
int main()
{
    return 0;
}
