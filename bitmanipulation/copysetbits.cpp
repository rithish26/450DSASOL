#include <bits/stdc++.h>
using namespace std;
int main()
{
int a;
int b;
cin>>a>>b;
int l,r;
cin>>l>>r;
int mask=(1<<(r-l+1))-1;
int maskl=(mask<<(l-1))&b;
a=a|maskl;
cout<<a<<endl;
}