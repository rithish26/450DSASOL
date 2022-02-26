#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],vector<int>&vis,int s,int par)
{
vis[s]=1;
for(auto x:adj[s])
{
    if(vis[x]==0)
    {
        if(dfs(adj,vis,x,s))
        {
            return true;
        }
    }
    else if(x!=par)
    {
        return true;
    }
}
return false;
}
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
int par;
int f=0;
for(int i=0;i<v;i++)
{
   if(vis[i]==0)
   {
     if(dfs(adj,vis,i,-1))
     {
         cout<<"true"<<endl;
         f=1;
         break;
     }
   }
}
if(f==0)
{
    cout<<"false"<<endl;
}
}