#include<bits/stdc++.h>
using namespace std;
#define type int
const int siz=2e5+7;

// 0 based indexing query idx=(idx & (idx+1))-1 amd update idx = (idx | (idx+1) )
// 1 based indexing query idx-=(idx & -idx) and update idx+=(idx & -idx)
// complexity O(logn) per query and update and space complexity O(n)
int n;
type bit1[siz],bit2[siz];
type get(type *bit,int x)
{
    type ret = 0;
    for(int i=x; i>=0; i=(i&(i+1))-1) ret+=bit[i];
    return ret;
}
void updt(type *bit,int x,int val)
{
    for(int i=x;i<n;i|=i+1) bit+=val;
}

void range_updt(int l,int r,int x)
{
    updt(bit1,l,x);
    updt(bit1,r+1,-x);
    updt(bit2,l,x*(l-1));
    updt(bit2,r+1,-x*r);
}
type gt(int x)
{
    return get(bit1,x)*x-get(bit2,x);
}
type query(int x,int y)
{
    return gt(y)-gt(x-1);
}
int main()
{

    return 0;
}
