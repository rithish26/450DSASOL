#include <bits/stdc++.h>
using namespace std;
void insert(vector<int>adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
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
queue<int>q;
int s;
cin>>s;
q.push(s);
bool visited[v+1];
for(int i=0;i<=v;i++)
{
    visited[i]=false;
}
visited[s]=true;
while(!q.empty())
{
    int u=q.front();
    q.pop();
    cout<<u<<" ";
    for(auto x:adj[u])
    {
        if(visited[x]==false)
        {
          visited[x]=true;
          q.push(x);
        }
    }
}

}