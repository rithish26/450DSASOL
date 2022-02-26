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

}
int src,dst,k;
cin>>src>>dst>>k;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
pq.push(make_tuple(0,src,0));
while(!pq.empty())
{
    
    auto[cost,u,stops]=pq.top();
    pq.pop();
    if(u==dst)
    {cout<<cost<<endl;
    break;}
    if(stops>k)
    {
        continue;
    }
    for(auto x:g[u])
    {
        auto [a,b]=x;
          pq.push(make_tuple(b+cost,a,stops+1));
    }
     
}
cout<<-1<<endl;
}