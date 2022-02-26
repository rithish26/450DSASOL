#include <bits/stdc++.h>
using namespace std;
int main()
{
int v,e;
cin>>v>>e;
vector<pair<int,int>>g[v];
for(int i=0;i<e;i++)
{
int x,y,wt;
cin>>x>>y>>wt;
g[x].push_back({y,wt});
g[y].push_back({x,wt});
}
int parent[v];
int key[v];
int mst[v];
for(int i=0;i<v;i++)
{
    key[i]=INT_MAX;
    mst[i]=false;
    parent[i]=-1;
}
key[0]=0;
for(int i=0;i<v-1;i++)
{
    int mini=INT_MAX;
    int u;
    for(int j=0;j<v;j++)
    {
        if(mst[j]==false&&key[j]<mini)
        {
            mini=key[j];
            u=j;
        }
    }
    mst[u]=true;
    for(auto it:g[u])
    {
        int a=it.first;
        int wt=it.second;
        if(mst[a]==false&&wt<key[a])
        {
          parent[a]=u;
          key[a]=wt;
        }
    }

}
for(int i=1;i<v;i++)
{
cout<<parent[i]<<"->"<<i<<endl;}
}