#include <bits/stdc++.h>
using namespace std;
int parent[10000];
int ranke[10000];
void makeset(int n)
{
    for(int i=1;i<=n;i++)
    {
        ranke[i]=0;
        parent[i]=i;
    }
}
int findpar(int u)
{
    if(u==parent[u])
    return u;
    return parent[u]=findpar(parent[u]);
}
void unione(int u,int v)
{
    u=findpar(u);
    v=findpar(v);
    if(ranke[u]<ranke[v])
    {
       parent[u]=v;
    }
    if(ranke[u]>ranke[v])
    {
       parent[v]=u;
    }
    else
    {
        parent[v]=u;
        ranke[u]++;
    }
}

int main()
{

}