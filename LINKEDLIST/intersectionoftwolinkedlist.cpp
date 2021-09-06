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
node*intersection(node*head1,node*head2)
{
    if(head1==NULL||head2==NULL)
    {
        return NULL;
    }
    node*curr1=head1;
    node*curr2=head2;
    node*res=NULL;
    node*curr=NULL;
    while(curr1!=NULL&&curr2!=NULL)
    {
        if(curr1->data==curr2->data)
        {
            node*temp=new node(curr1->data);
            if(res==NULL)
            {
                res=temp;

            }
            else
            {
                curr->l=temp;
            }
            curr=temp;
            curr1=curr1->l;
            curr2=curr2->l;
        }
        else if(curr1->data<curr2->data)
        {
            curr1=curr1->l;
        }
        else if(curr1->data>curr2->data)
        {
            curr2=curr2->l;
        }
    }
    return res;
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
int m;
cin>>m;
node*head1=NULL;
for(int i=0;i<m;i++)
{
    int x;
    cin>>x;
    head1=insert(head1,x);
}
node*res=intersection(head,head1);
display(res);
}