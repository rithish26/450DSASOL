#include <bits/stdc++.h>
using namespace std;
const int INF =1e9;
int main()
{
    int n;
    cin>>n;
vector<vector<int>>graph;
for(int i=0;i<n;i++)
{
    vector<int>temp;
    for(int j=0;j<n;j++)
    {
        int x;
        cin>>x;
        if(x==9)
        {
            x=INF;
        }
        temp.push_back(x);
    }
    graph.push_back(temp);
}
vector<vector<int>>dist=graph;
for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][k]+dist[k][j]<dist[i][j])
            {
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
}
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<"INF"<<endl;
            }
            else
            cout<<dist[i][j]<<endl;
        }
    }
}