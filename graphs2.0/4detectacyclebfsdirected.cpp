#include <bits/stdc++.h>
using namespace std;
void insert(vector<int>adj[],int x,int y)
{
    adj[x].push_back(y);
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
vector<int>indegree(v,0);
for(int i=0;i<v;i++)
{
    for(auto x:adj[i])
    {
        indegree[x]++;
    }
}
queue<int>q;
for(int i=0;i<v;i++)
{
    if(indegree[i]==0)
     q.push(i);
}
int cnt=0;
vector<int>top_order;
while(!q.empty())
{
    int u=q.front();
    q.pop();
    top_order.push_back(u);
    for(auto x:adj[u])
    {
        if(--indegree[x]==0)
        {
            q.push(x);
        }
    }
    cnt++;
}
if(cnt!=v)
cout<<"TRUE"<<endl;
else
cout<<"FALSE"<<endl;
}