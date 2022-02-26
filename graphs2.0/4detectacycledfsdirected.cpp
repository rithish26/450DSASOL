#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],vector<int>vis,vector<int>order,int i)
{
vis[i]=1;
order[i]=1;
for(auto x:adj[i])
{
    if(vis[x]==0)
    {
        if(dfs(adj,vis,order,x))
        {
            return true;
        }
    }
    else if(order[x]==1)
    {
        return true;
    }
}
order[i]=0;
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
}
vector<int>vis(v,0);
vector<int>order(v,0);
int f=0;
for(int i=0;i<v;i++)
{
if(dfs(adj,vis,order,i))
{
cout<<"True"<<endl;
f=1;
break;
}

}
if(f==0)
cout<<"false"<<endl;
}