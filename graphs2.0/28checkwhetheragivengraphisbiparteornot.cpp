#include <bits/stdc++.h>
using namespace std;
int f=0;
void dfs(int i,int par,int col,vector<int>adj[],vector<int>&vis)
{
    vis[i]=col;
    for(auto x:adj[i])
    {
        if(vis[x]==-1)
        dfs(x,i,3-col,adj,vis);
        else if(x!=par&&col==vis[x])
        {
            f=1;
            break;
        }
    }
    
}
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v+1];
for(int i=0;i<e;i++)
{
int x,y;
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
vector<int>vis(v+1,-1);
dfs(1,0,1,adj,vis);
if(f==1)
{
    cout<<"not bipirate"<<endl;
}
else
{
    cout<<"bipirate"<<endl;
}

}