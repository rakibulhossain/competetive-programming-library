#include<bits/stdc++.h>
using namespace std;
const int siz=1007;
#define type int
type bit[4][siz][siz];
int n;

void update(int x,int y,type val,int idx)
{
    for(int i=x;i<n;i|=(i+1))
    {
        for(int j=y;j<n;j|=(j+1))
        {
            bit[idx][i][j]+=val;
        }
    }
}

type query(int x,int y,int idx)
{
    type ret=0;
    for(int i=x;i>=0;i=(i&(i+1))-1)
    {
        for(int j=y;j>=0;j=(j&(j+1))-1)
        {
            ret+=bit[idx][i][j];
        }
    }
    return ret;
}


void updt(int x1,int y1,int x2,int y2,type val)
{
    update(x1,y1,val,0);
    update(x1,y2+1,-val,0);
    update(x2+1,y1,-val,0);
    update(x2+1,y2+1,val,0);

    update(x1,y1,val*(1-y1),1);
    update(x1,y2+1,val*y2,1);
    update(x2+1,y1,val*(y1-1),1);
    update(x2+1,y2+1,-val*y2,1);

    update(x1,y1,val*(1-x1),2);
    update(x1,y2+1,val*(x1-1),2);
    update(x2+1,y1,val*x2,2);
    update(x2+1,y2+1,-val*x2,2);

    update(x1,y1,(x1-1)*(y1-1)*val,3);
    update(x1,y2+1,-y2*(x1-1)*val,3);
    update(x2+1,y1,-x2*(y1-1)*val,3);
    update(x2+1,y2+1,x2*y2*val,3);
}




type get(int x,int y){
    return query(x,y,0)*x*y+query(x,y,1)*x+query(x,y,2)*y+query(x,y,3);
}

type qry(int x1,int y1,int x2,int y2)
{
    return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
}


int main()
{

    return 0;
}
