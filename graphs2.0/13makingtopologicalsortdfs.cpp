#include <bits/stdc++.h>
using namespace std;
void dfs(int i,vector<bool>&vis,stack<int>&stk,vector<int>adj[])
{
    vis[i]=1;
    
    for(auto x:adj[i])
    {
        if(vis[x]==0)
        {
            dfs(x,vis,stk,adj);
        }
    }
    stk.push(i);
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


stack<int>stk;
vector<bool>vis(v,0);
for(int i=0;i<v;i++)
{
    if(vis[i]==0)
    dfs(i,vis,stk,adj);
}
while (stk.empty() == false) {
        cout << stk.top() << " ";
        stk.pop();
    }
}