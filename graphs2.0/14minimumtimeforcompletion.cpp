#include <bits/stdc++.h>
using namespace std;
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v+1];
vector<int>in(v+1,0);
for(int i=0;i<e;i++)
{
int x,y;
cin>>x>>y;
adj[x].push_back(y);
}
for(int i=1;i<=v;i++)
{
    for(auto x:adj[i])
    {
        in[x]++;
    }
}
vector<int>ans(v+1,0);
queue<int>q;
for(int i=1;i<=v;i++)
{
    if(in[i]==0)
    {
        q.push(i);
        ans[i]=1;
    }
}
while(!q.empty())
{
    int val=q.front();
    q.pop();
    for(auto x:adj[val])
    {
        if(--in[x]==0)
        {
            ans[x]=ans[val]+1;
            q.push(x);
        }
    }
}
for(int i=1;i<=v;i++)
{
    cout<<ans[i]<<endl;
}
return 0;
}