#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return !b? a:gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int x1,y1;
    int g= exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}
bool find_any_sol(int a,int b,int c,int &x,int &y,int &g){
    g= exgcd(abs(a),abs(b),x,y);
    if(c%g) return false;
    x*=c/g;
    y*=c/g;
    if(a<0) x=-x;
    if(b<0) y=-y;
    return true;
}
void shift_solution(int &x,int &y,int a,int b,int cnt){
    x+=cnt*b;
    y-=cnt*a;
}
int find_all_sol(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    if(a==0&&b==0) return (maxx-minx+1)*(maxy-miny+1)*(c==0);
    if(a==0) return (maxx-minx+1)*(c%b==0);
    if(b==0) return (maxy-miny+1)*(c%a==0);
    int x,y,g;
    if(!find_any_sol(a,b,c,x,y,g)) return 0;
    a/=g;
    b/=g;
    int sign_a= (a>0)?1:-1;
    int sign_b= (b>0)?1:-1;
    shift_solution(x,y,a,b,(minx-x)/b);
    if(x<minx)
        shift_solution(x,y,a,b,sign_b);
    if(x>maxx)
        return 0;
    int lx1=x;

    shift_solution(x,y,a,b,(maxx-x)/b);
    if(x>maxx)
        shift_solution(x,y,a,b,-sign_b);
    int rx1=x;
    shift_solution(x,y,a,b,-(miny-y)/a);
    if(y<miny)
        shift_solution(x,y,a,b,-sign_a);
    if(y>maxy) return 0;
    int lx2=x;
    shift_solution(x,y,a,b,-(maxy-y)/a);
    if(y>maxy)
        shift_solution(x,y,a,b,sign_a);
    int rx2=x;
    if(lx2>rx2) swap(lx2,rx2);
    int lx=max(lx1,lx2);
    int rx=min(rx1,rx2);
    if(lx>rx) return 0;
    return (rx-lx)/abs(b)+1;

}
int main(){
    // if a =0 swap (a,b)
    return 0;
}
