#include <bits/stdc++.h>
using namespace std;
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v];
for(int i=0;i<e;i++)
{
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int res[v];
bool available[v];
res[0]=0;
for(int i=1;i<v;i++)
res[i]=-1;
for(int i=0;i<v;i++)
{
    available[i]=false;
}
int cn=0;
for(int i=1;i<v;i++)
{
    for(auto x:adj[i])
    {
        if(res[x]!=-1)
        {
            available[res[x]]=true;
        }
    }

int cr;
for(cr=0;cr<v;cr++)
{
    if(available[cr]==false)
    {
        break;
    }
}
res[i]=cr;
cn=max(cr+1,cn);
for(auto x:adj[i])
    {
        if(res[x]!=-1)
        {
            available[res[x]]=false;
        }
    }
}
cout<<cn<<endl;
for(int i=0;i<v;i++)
{
    cout<<res[i]<<" ";
}
cout<<endl;
}