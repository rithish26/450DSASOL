#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>&vis,stack<int>&st,vector<int>adj[],int i)
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(vis[x]==0)
        {
            dfs(vis,st,adj,x);
        }
    }
 st.push(i);
}
int main()
{
int n;
int k;
cin>>n>>k;
string dict[n];
for(int i=0;i<n;i++)
{
    cin>>dict[i];
}
vector<int>adj[k];
for(int i=0;i<n-1;i++)
{
    string s1=dict[i];
    string s2=dict[i+1];
    for(int j=0;j<min(s1.size(),s2.size());j++)
    {
        if(s1[j]!=s2[j])
        {
            int y=s2[j]-'a';
            int x=s1[j]-'a';
            adj[x].push_back(y);
            break;
        }
    }

}
vector<int>vis(k,0);
stack<int>st;
for(int i=0;i<k;i++)
{
    if(vis[i]==0)
dfs(vis,st,adj,i);
}
while (st.empty() == false) {
        cout << char(st.top()+'a') << " ";
        st.pop();
    }
    cout<<endl;
}