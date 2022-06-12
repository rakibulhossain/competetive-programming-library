#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll mod2=mod*mod;
struct matrix
{
    vector< vector<ll> >mat;
    int rows,cols;
    matrix() {}
    matrix(vector< vector<ll> >v): mat(v),rows((int)v.size()),cols((int)v[0].size()) {}
    static matrix indentity(int nn)
    {
        vector<vector<ll> >ind(nn,vector<ll>(nn,0));
        for(int i=0; i<nn; i++)
            ind[i][i]=1;
        return matrix(ind);
    }

    matrix operator*(const matrix &x)const
    {
        int mm=x.cols;
        vector< vector<ll> > res(cols,vector<ll>(x.cols,0));
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<mm; j++)
            {
                ll tmp=0;
                for(int k=0; k<cols; k++)
                {
                    tmp+=(mat[i][k]*1ll*x.mat[k][j]);
                    while(tmp>=mod2)
                    {
                        tmp-=mod2;
                    }
                }
                res[i][j]=tmp%mod;
            }
        }
        return matrix(res);
    }
};

matrix power[107];
matrix M;
void save()
{
    power[0]=M;
    for(int i=1; i<=100; i++)
        power[i]=power[i-1]*power[i-1];
}

matrix expo(int p)
{
    matrix result=matrix::indentity((int)power[0].mat[0].size());
    int cnt=0;
    while(p)
    {
        if(p&1)
        {
            result=result*power[cnt];
        }
        cnt++;
        p>>=1;
    }
    return result;
}

vector< vector <ll > >v(2,(vector<ll>(2,0)));
void solve()
{
    v[0][0]=v[1][0]=v[0][1]=1;
    M.mat=v;
    M.rows=v.size();
    M.cols=v[0].size();
    matrix initial({{1ll},{0ll}});
    save();
    int n;
    while(cin>>n)
    {
        n-=1;
        cout<<(expo(n)*initial).mat[0][0]<<endl;
    }
}
