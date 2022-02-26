#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&vis,vector<vector<int>>&v,int sr,int sc,int n,int newc,int org)
{
    if(sr>=n||sc>=n||sc<0||sr<0||vis[sr][sc]==1||v[sr][sc]!=org)
    {
        return;
    }
    vis[sr][sc]=1;
    v[sr][sc]=newc;
    dfs(vis,v,sr+1,sc,n,newc,org);
     dfs(vis,v,sr-1,sc,n,newc,org);
      dfs(vis,v,sr,sc+1,n,newc,org);
       dfs(vis,v,sr,sc-1,n,newc,org);



}
int main()
{
vector<vector<int>>v;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    vector<int>temp;
    for(int j=0;j<n;j++)
    {
        int x;
        cin>>x;
        temp.push_back(x);
    }
    v.push_back(temp);
}
int sr,sc;
cin>>sr>>sc;
int org=v[sr][sc];
int newc;
cin>>newc;
vector<vector<int>>vis;
for(int i=0;i<n;i++)
{
    vector<int>temp;
    for(int j=0;j<n;j++)
    {
      temp.push_back(0);
    }
    vis.push_back(temp);
}
if(org!=newc)
dfs(vis,v,sr,sc,n,newc,org);
for(int i=0;i<n;i++)
{

    for(int j=0;j<n;j++)
    {
     cout<<v[i][j]<<" ";
    }
    cout<<endl;
}
}