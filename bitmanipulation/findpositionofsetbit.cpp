#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int count=0;
int k=n;
while(n>0)
{
count+=n&1;
n=n>>1;
}
if(count==1)
{
   int i=1;
   int pos=1;
   while(!(i&k))
   {
       i=i<<1;
       pos++;
   }
   cout<<pos<<endl;
}
else
{
    cout<<-1<<endl;
}
}