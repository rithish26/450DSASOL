#include <bits/stdc++.h>
using namespace std;
int main()
{
int v;
int e;
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
vector<int>par(v,-1);
queue<int>q;
int f=0;
for(int i=0;i<v;i++)
{
if(vis[i]==0&&f==0)
{
vector<int>par(v,-1);
queue<int>q;
vis[i]=1;
q.push(i);

while(!q.empty())
{
    int u=q.front();
    q.pop();
    for(auto x:adj[u])
    {
        if(vis[x]==0)
        {
            vis[x]=1;
            q.push(x);
            par[x]=u;
        }
        else if(par[u]!=x)
        {
        cout<<"true"<<endl;
        f=1;
        break;
        }
    }
  if(f==1)
  break;
}

}

}
if(f==0)
{
    cout<<"false"<<endl;
}


}