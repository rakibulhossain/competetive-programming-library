#include<bits/stdc++.h>
using namespace std;
const int siz=1e5+7;
int arr[siz],ran[siz];
int find_set(int  x)
{
    if(x!=arr[x])
        arr[x]=find_set(arr[x]);
    return arr[x];
}
void create_set(int x)
{
    arr[x]=x;
    ran[x]=0;
    return;
}
void merge_set(int x,int y)
{
    int px=find_set(x);
    int py=find_set(y);
    if(ran[px]>ran[py])
        arr[py]=px;
    else
        arr[px]=py;
    if(ran[px]==ran[py])
        ran[py]++;
}
int main()
{

    return 0;
}

