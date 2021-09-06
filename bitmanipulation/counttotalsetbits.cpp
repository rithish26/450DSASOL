#include<bits/stdc++.h>
using namespace std;
int largestpowerof2(int n)
{
    int x=0;
    while((1<<x)<=n)
    {
        x++;
    }
    return x-1;
}
int recur(int n)
{
    if(n==0)
    {
        return 0;
    }
 int x=largestpowerof2(n);

    int bitsraised=x*(1<<(x-1));
    int msbraised=n-(1<<x)+1;
    int rest=n-(1<<x);

    return bitsraised+msbraised+recur(rest);
}
int main()
{
    int n;
    cin>>n;
   cout<<recur(n)<<endl;

}