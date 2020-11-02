#include<bits/stdc++.h>
using namespace std;

struct kmp{
    int n;
    vector<int>failure;
    kmp(const string &s): failure((int)s.length()+1,0),n((int)s.length()){
        // generating failure table for pattern
        for(int i=2;i<=n;i++)
        {
            int j=failure[i-1];
            while(true){
                if(s[i-1]==s[j]){
                    j++;
                    break;
                }
                else if(j==0) break;
                else j=failure[j];
            }
            failure[i]=j;
        }
    }

    bool match(const string &s,const string &text)
    {
        int m=(int)text.length();
        int i=0,j=0;
        while(true){
            if(j==m) return false;
            if(text[j]==s[i]){
                i++; j++;
                if(i==n) return true;
            }
            else if(i==0) j++;
            else i=failure[i];
        }
        return false;
    }
};



int main()
{

    return 0;
}
