#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int siz=1e5+7;
deque<pii>m;
int val,a[siz],n,q;
void rmq(int q)
{
    for(int i=0;i<n;i++){
        val=a[i];
        while(!m.empty()&&m.back().first>=val)
            m.pop_back();
        m.push_back({val,i});
        while(!m.empty()&&m.front().second<=i-q)
            m.pop_front();
        if(i>=q-1)
            cout<<m.front().first<<' ';
    }
}
int  main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    rmq(q);
}
