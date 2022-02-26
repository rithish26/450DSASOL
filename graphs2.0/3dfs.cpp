#include <bits/stdc++.h>
using namespace std;
void insert(vector<int>adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void dfs(vector<int>adj[],bool visited[],int s)
{
visited[s]=true;
cout<<s;
for(auto x:adj[s])
{
    if(visited[x]==false)
    dfs(adj,visited,x);
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
    insert(adj,x,y);
}
bool visited[v+1];
for(int i=0;i<v;i++)
{
 visited[i]=0;
}
int s;
cin>>s;
dfs(adj,visited,s);
}