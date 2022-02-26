#include <bits/stdc++.h>
using namespace std;

int main()
{
int n;
int e;
cin>>n>>e;
vector<pair<int,int>>p;
for(int i=0;i<e;i++)
{
    int x,y;
    cin>>x>>y;
    p.push_back({x,y});
}
vector<int>adj[n];
vector<int>in(n,0);
for(auto x:p)
{
    adj[x.second].push_back(x.first);
    in[x.first]++;
}
queue<int>q;
for(int i=0;i<n;i++)
{
    if(in[i]==0)
    {
   q.push(i);
    }
}
int count=0;
while(!q.empty())
{
    int u=q.front();
    q.pop();
    count++;
    for(auto s:adj[u])
    {
        if(--in[s]==0)
        {
            q.push(s);
        }
    }
}
if(count!=n)
{
cout<<"false"<<endl;
}
else cout<<"true"<<endl;
}