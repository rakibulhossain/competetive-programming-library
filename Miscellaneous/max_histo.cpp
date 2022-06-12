#include<bits/stdc++.h>
using namespace std;
int max_area(int ar[],int m)
{
    int a,ma_area,i=0;
    a=ma_area=0;
    stack<int>area;
    while(i<m)
    {
        if(area.empty()||(ar[area.top()]<=ar[i]))
            area.push(i++);
        else
        {
            int top=ar[area.top()];
            int a=ar[area.top()]*i;
            area.pop();
            //as we pop so we use i-area.top()-1
            if(!area.empty())
                a=top*(i-area.top()-1);
            ma_area=max(a,ma_area);
        }
    }
    while(!area.empty())
    {
        int top=ar[area.top()];
        int a=ar[area.top()]*i;
        area.pop();
        if(!area.empty())
            a=top*(i-area.top()-1);
        ma_area=max(a,ma_area);
    }
    return ma_area;
}
int main()
{
    int n,m,in,m_area;
    while(cin>>n>>m)
    {
        int a[100]={0};
        m_area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>in;
                if(in)
                    a[j]+=in;
                else
                    a[j]=0;
            }
            m_area=max(max_area(a,m),m_area);
        }
        cout<<m_area<<endl;
    }
    return 0;
}

