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
}
vector<int>in(v,0);
vector<int>ans;
queue<int>q;
for(int i=0;i<v;i++)
{
for(auto x:adj[i])
{
    in[x]+=1;
}
}
for(int i=0;i<v;i++)
{
    if(in[i]==0)
    {
        q.push(i);
    }
}
while(!q.empty())
{
    int td=q.front();
    q.pop();
    ans.push_back(td);
    for(auto x:adj[td])
    {
        in[x]--;
        if(in[x]==0)q.push(x);
    }
}
for(int i=0;i<ans.size();i++)
{
cout<<ans[i]<<" ";
}
cout<<endl;
}