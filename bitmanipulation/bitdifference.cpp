#include <bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
int xore=a^b;
int count=0;
while(xore)
{
count++;
xore&=(xore-1);
}
cout<<count<<endl;
}