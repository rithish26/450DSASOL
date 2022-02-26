#include <bits/stdc++.h>
using namespace std;
int main()
{
int v;
int e;
cin>>v>>e;
int g[v][v];
memset(g,0,sizeof(g));
for(int i=0;i<e;i++)
{
    int x,y;
    cin>>x>>y;
    g[x][y]=1;
    g[y][x]=1;
}
for(int i=0;i<v;i++)
{
    for(int j=0;j<v;j++)
    {
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
}
}