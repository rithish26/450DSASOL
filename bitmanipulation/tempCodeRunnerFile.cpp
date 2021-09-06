int setbit=n&~(n-1);
int count=0;
while(n)
{
    count++;
    n&=(n-1);

}
if(count==1)
{
    cout<<setbit<<endl;
}
else
{
    cout<<-1<<endl;
}