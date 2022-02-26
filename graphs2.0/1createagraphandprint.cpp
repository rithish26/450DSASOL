#include<bits/stdc++.h>
using namespace std;
void insert(int x,int y,vector<int>adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void print(vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
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
        insert(x,y,adj);
    }
   print(adj,v);
}