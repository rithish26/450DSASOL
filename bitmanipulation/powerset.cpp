#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
char a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
unsigned int powset=pow(2,n);
int counter,j;
for(counter=0;counter<powset;counter++)
{
    for(j=0;j<n;j++)
    {
        if(counter&1<<j)
        {
            cout<<a[j]<<" ";
        }
    }
    cout<<endl;
}
}