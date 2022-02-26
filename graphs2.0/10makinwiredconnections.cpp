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
vector<int>vis(v,0);
int count=0;
for(int i=0;i<v;i++)
{
    if(vis[i]==0)
    {
    queue<int>q;
    q.push(i);
    count++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x:adj[i])
        {
          if(vis[x]==0)
          {
              vis[x]=1;
              q.push(x);
          }
        }
    }
    }


}
cout<<count-1<<endl;
}