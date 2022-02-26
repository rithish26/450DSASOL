#include <bits/stdc++.h>
using namespace std;
vector<int>order;
void dfs(int i,vector<int>&vis,vector<int>adj[])
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(vis[x]==0)
        dfs(x,vis,adj);
    }
    order.push_back(i);
}
void rdfs(int s,vector<int>&vis,vector<int>adj[])
{
    vis[s]=1;
    for(auto x:adj[s])
    {
        if(vis[x]==0)
        rdfs(x,vis,adj);
    }
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
}
order.clear();
vector<int>rev[v];
for(int i=0;i<v;i++)
{
   for(auto x:adj[i])
   {
       rev[x].push_back(i);
   }
}
vector<int>vis(v,0);
for(int i=0;i<v;i++)
{
    if(!vis[i])
    {
        dfs(i,vis,adj);
    }
}
vector<int>vis1(v,0);
int c=0;
for(int i=v-1;i>=0;i--)
{
    if(vis1[order[i]]!=1)
    {
     rdfs(order[i],vis1,rev);
     c++;
    }
}
cout<<c<<endl;
}