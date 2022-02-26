#include <bits/stdc++.h>
using namespace std;

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
int source;
cin>>source;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
vector<int> distTo(v+1,INT_MAX); 
distTo[source] = 0;
pq.push(make_pair(0,source));
while(!pq.empty())
{
    int dist=pq.top().first;
    int prev=pq.top().second;
    pq.pop();
 
    for(auto x:adj[prev])
    {
       int next=x.first;
       int nextdist=x.second;
       if(distTo[next]>distTo[prev]+nextdist)
       {
           distTo[next]=distTo[prev]+nextdist;
           pq.push({distTo[next],next});
       }

    }

}
for(int i=0;i<v;i++)
{
    cout<<distTo[i]<<endl;
}
cout<<endl;
}