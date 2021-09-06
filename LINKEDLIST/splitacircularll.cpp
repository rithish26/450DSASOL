#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*l;

    node(int x)
    {
        data=x;
        l=NULL;
      
    }
};
node* insert(node*head,int x)
{
if(head==NULL)
{
    return new node(x);
}
node*curr=head;
while(curr->l!=NULL)
{
    curr=curr->l;
}
curr->l=new node(x);
return head;
}
void display(node*head)
{
    node*cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->l;
    }

}
void reversell(node**head)
{
    node*nex=NULL;
    node*prev=NULL;
    node*curr=*head;
    while(curr!=NULL)
    {
       nex=curr->l;
       curr->l=prev;
       prev=curr;
       curr=nex; 
    }
  *head=prev;
}
bool checkifcircular(node*head)
{
    node*nod=head->l;
    while(nod!=NULL&&nod!=head)
    {
        nod=nod->l;
    }
    return (nod==head)?true:false;
}
void split(node*head,node**head1,node**head2)
{
    node*fast=head;
    node*slow=head;
    while(fast->l!=head&&fast->l->l!=head)
    {
        fast=fast->l->l;
        slow=slow->l;
    }
    if(fast->l->l==head)
    {
        fast=fast->l;
    }
    *head1=head;
    if(head->l!=head)
    {
        *head2=slow->l;
    }
    fast->l=slow->l;
    slow->l=head;
}
int main()
{
int n;
cin>>n;
node*head=NULL;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    head=insert(head,x);
}
node*curr=head;
while(curr->l!=NULL)
{
   curr=curr->l;
}
curr->l=head;


}