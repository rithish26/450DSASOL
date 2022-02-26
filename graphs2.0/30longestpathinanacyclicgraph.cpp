#include <bits/stdc++.h>
using namespace std;
vector<int>order;
void dfs(vector<pair<int,int>>adj[],vector<int>&vis,int i)
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(vis[x.first]==0)
        dfs(adj,vis,x.first);
    }
    order.push_back(i);
}
int main()
{
int v,e;
cin>>v>>e;

vector<pair<int,int>>adj[v];
for(int i=0;i<e;i++)
{
    int x,y,w;
    cin>>x>>y>>w;
    adj[x].push_back({y,w});
}
int src;
cin>>src;
vector<int>vis(v,0);
for(int i=0;i<v;i++)
{
    if(!vis[i])
    dfs(adj,vis,i);
}
vector<int>dist(v);
for(int i=0;i<v;i++)
{
    dist[i]=INT_MIN;
}
dist[src]=0;
for(int i=v-1;i>=0;i--)
{
if(dist[order[i]]!=INT_MIN)
{
    for(auto x:adj[order[i]])
    {
        int u=dist[x.first];
        int w=x.second;
        int y=dist[order[i]];
        if(y+w>u)
        dist[x.first]=y+w;
    }

}
}
for(int i=0;i<v;i++)
{
    if(i!=src&&dist[i]!=INT_MIN)
    {
        cout<<src<<"->"<<i<<"="<<dist[i]<<endl;
    }
}
}