#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int xore=a[0];
 int setbit;
 int d=0;
 int e=0;
for(int i=1;i<n;i++)
{
xore^=a[i];
}
setbit=xore&~(xore-1);
cout<<xore<<endl;
cout<<setbit<<endl;
for(int i=0;i<n;i++)
{
    if(a[i]&setbit)
    {
        d=d^a[i];
    }
    else
    {
        e=e^a[i];
    }

}
cout<<d<<" "<<e<<endl;
}