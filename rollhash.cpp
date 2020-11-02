#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int gen_base(const int bef,const int aft)
{
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base=uniform_int_distribution<int>(bef+1,aft)(mt_rand);
    return base%2==0? base-1 : base;
}


struct rollhash
{
    static const int mod = (int)1e9+123; // mod
    vector<ll>pref1; // hash by mod
    vector<ull>pref2; // hash by 2^64

    static vector<ll>pow1; // pow of base by mod
    static vector<ull>pow2; // pow of base by 2^64

    static int base; // base of hash

    inline void init(const string& s)
    {
        pref1.push_back(0);
        pref2.push_back(0);

        int n=s.length();

        while((int)pow1.size()<=n)
        {
            pow1.push_back((1ll*pow1.back()*base)%mod);
            pow2.push_back(pow2.back()*base);
        }

        for(int i=0; i<n; i++)
        {
            assert(base>s[i]);

            pref1.push_back((pref1[i]+1ll*(s[i]*pow1[i]))%mod);
            pref2.push_back(pref2[i]+(s[i]*pow2[i]));
        }

    }

    inline pair<ll,ull> operator()(const int pos,const int len,const int mxpow=0)const{

        ll hash1=pref1[pos+len]-pref1[pos];
        ull hash2=pref2[pos+len]-pref2[pos];


        if(hash1<0) hash1+=mod;

        if(mxpow)
        {
            hash1=(1ll*hash1*pow1[mxpow-pos-len+1])%mod;
            hash2=hash2*pow2[mxpow-pos-len+1];
        }
        return make_pair(hash1,hash2);

    }

};

int rollhash::base((int)1e9+7);
vector<ll> rollhash::pow1{1};
vector<ull> rollhash::pow2{1u};


int main()
{
    return 0;
}
