#include <bits/stdc++.h>
using namespace std;
vector<string>s;
void dfs(vector<vector<int>>a,vector<vector<int>>&vis,int n,string p,int i,int j)
{
    if(i<0||i>=n||j<0||j>=n)
    return;
    if(vis[i][j]==1||a[i][j]==0)
    return;
    if(i==n-1&&j==n-1)
    {
        s.push_back(p);
    }
    vis[i][j]=1;
    dfs(a,vis,n,p+"U",i-1,j);
    dfs(a,vis,n,p+"D",i+1,j);
    dfs(a,vis,n,p+"R",i,j+1);
    dfs(a,vis,n,p+"L",i,j-1);
    vis[i][j]=0;
}
int main()
{
int n;
cin>>n;
vector<vector<int>>a;
for(int i=0;i<n;i++)
{
    vector<int>temp;
    for(int j=0;j<n;j++)
    {
        int x;
        cin>>x;
        temp.push_back(x);
    }
    a.push_back(temp);
}
vector<vector<int>>vis(n,vector<int>(n));
if(a[0][0]==0)
{
    for(string x:s)
    {
        cout<<x;
    }
    cout<<endl;
}
if(a[n-1][n-1]==0)
{
    for(string x:s)
    {
        cout<<x;
    }
}
string p="";
dfs(a,vis,n,p,0,0);
for(int i=0;i<s.size();i++)
{
 cout<<s[i]<<" ";
}
cout<<endl;
}