#include <bits/stdc++.h>
using namespace std;

int main()
{
int a,b;
cin>>a>>b;

int q=0;
int i;
while(a>=b)
{
  for(i=0;;i++)
  {
    if((b*(1<<i))>a)
    {
      break;
    }
  }
  a-=b*(1<<(i-1));
  q+=1<<(i=1);
}
cout<<q<<endl;
}