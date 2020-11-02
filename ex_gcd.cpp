#include<bits/stdc++.h>
using namespace std;
struct type{int x,y,d;};
type exgcd(int a,int b){
    if(b==0) return {1,0,a};
    type xx=exgcd(b,a%b);
    return {xx.y,xx.x-((a/b)*xx.y),xx.d};
}
int main()
{

    return 0;
}
