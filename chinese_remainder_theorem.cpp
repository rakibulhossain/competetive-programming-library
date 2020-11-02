#include<bits/stdc++.h>
using namespace std;
#define type int
type exgcd(type a,type b,type &x,type &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    type x1,y1;
    type d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
type Lcm(type a,type b){
    return (a/__gcd(a,b))*b;
}
struct crt{
    type n;
    type *a,*b;
    crt(type x,type *aa,type *bb):n(x),a(aa),b(bb){}
    type solve(){
        type ans=a[0];
        type lcm= b[0];
        for(int i=1;i<n;i++){
            type x1,y1;
            type d=exgcd(lcm,b[i],x1,y1);
            if((a[i]-ans)%d) {
                return -1;
            }
            ans=(ans+(x1*(a[i]-ans)/d)% (b[i]/d)*lcm)%(lcm*b[i]/d);
            lcm=lcm*b[i]/d;
            if(ans<0) ans+=lcm;
        }
        return ans;
    }
};
int main()
{

    return 0;
}
