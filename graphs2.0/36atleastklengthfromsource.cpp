#include <bits/stdc++.h>
using namespace std;
bool morepath(int src,int k,vector<bool>&vis,vector<pair<int,int>>adj[])
{
    vis[src]=true;
    if(k<=0)
    return true;
    for(auto x: adj[src])
    {
        if(vis[x.first]==true)
        {
            continue;
        }   
       int u= x.first;
       int wt=x.second;
       if(k<=wt)
       return true;
       if(morepath(u,k-wt,vis,adj))
       return true;
    }
    vis[src]=false;
return false;
}
int main()
{
int v,e;
cin>>v>>e;
vector<pair<int,int>>adj[v];
for(int i=0;i<e;i++)
{
    int x,y,wt;
    cin>>x>>y>>wt;
    adj[x].push_back({y,wt});
    adj[y].push_back({x,wt});
}
int src;
int k;
cin>>src>>k;
vector<bool>vis(v,false);
vis[src]=true;
cout<<morepath(src,k,vis,adj)<<endl;

}