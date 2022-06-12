#include<bits/stdc++.h>
using namespace std;
struct node
{
    int words,prefixs;
    node* edges[26];
    node()
    {
        words=prefixs=0;
        for(int i=0;i<26;i++)
            edges[i]=NULL;
    }
}*root;
void insert_(string s){
    node* curr=root;
    for(int i=0;i<s.length();i++){
        int a=(s[i]-'a');
        if(curr->edges[a]==NULL)
            curr->edges[a]=new node();
        curr=curr->edges[a];
        curr->prefixs++;
    }
    curr->words++;
}
int countwords(string s){
    node* curr=root;
    for(int i=0;i<s.length();i++){
        int a=(s[i]-'a');
        if(curr->edges[a]==NULL)
            return 0;
        curr=curr->edges[a];
    }
    return curr->words;
}
int countprefix(string s){
    node* curr=root;
    for(int i=0;i<s.length();i++){
        int a=(s[i]-'a');
        if(curr->edges[a]==NULL)
            return 0;
        curr=curr->edges[a];
    }
    return curr->prefixs;
}
void del(node* curr){
    for(int i=0;i<26;i++)
        if(curr->edges[i])
            del(curr->edges[i]);
    delete(curr);
}
int main()
{
    return 0;
}

