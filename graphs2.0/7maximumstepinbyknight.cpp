#include <bits/stdc++.h>
using namespace std;
bool issafe(int x,int y,int n)
{
    if(x>=0&&y>=0&&x<n&&y<n)
    {
        return true;
    }
    return false;
}

int main()
{
int n;
cin>>n;
vector<int>kp;
for(int i=0;i<2;i++)
{
    int x;
    cin>>x;
    kp.push_back(x);
}
vector<int>t;
for(int i=0;i<2;i++)
{
    int x;
    cin>>x;
    t.push_back(x);
}
int x1=kp[0];
int y1=kp[1];
int x2=t[0];
int y2=t[1];
if(x1==x2&&y1==y2)
{
    cout<<"done"<<endl;
}
int a[n][n];
for(int i=0;i<n;i++)
{

    for(int j=0;j<n;j++)
    {
     a[i][j]=0;  
    }

}
int dx[]={ -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[]={ -1, -2, -2, -1, 1, 2, 2, 1 };
queue<pair<int,int>>q;
q.push({x1-1,y1-1});
while(!q.empty())
{
    auto curr=q.front();
  
    int i=curr.first;
    int j=curr.second;
      q.pop();
    for(int k=0;k<8;k++)
    {
        if(issafe(i+dx[k],j+dy[k],n)&&a[i+dx[k]][j+dy[k]]==0)
        {
        a[i+dx[k]][j+dy[k]]=a[i][j]+1;
        q.push({i+dx[k],j+dy[k]});
        }
    }
}
cout<<a[x2-1][y2-1]<<endl;
}