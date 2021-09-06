#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int count=0;
/* while(n>0)
{
count++;
n&=(n-1);
} */

while(n>0)
{
    count+=n&1;
    n=n>>1;
}
if(count==1)
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}
}