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
node* reversepart(node*head,int k)
{
node*curr=head;
node*prev=NULL;
node*next;
int count=0;
while(count<k&&curr!=NULL)
{
    next=curr->l;
    curr->l=prev;
    prev=curr;
    curr=next;
    count++;
}
if(next!=NULL)
{
    head->l=reversepart(next,k);
}
return prev;
}
int findpoint(node*head1,node*head2)
{
    node*ptr1=head1;
    node*ptr2=head2;
    int c1=0;
    int c2=0;
    node*curr1=head1;
    node*curr2=head2;
    while(ptr1!=NULL)
    {
        ptr1=ptr1->l;
        c1++;
    }
    while(ptr2!=NULL)
    {
        ptr2=ptr2->l;
        c2++;
    }
    int diff=abs(c2-c1);
    if(c1>c2)
    {
        for(int i=0;i<diff;i++)
        {
            curr1=curr1->l;
        }
    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            curr2=curr2->l;
        }
    }
    while(curr1!=curr2)
{
    curr1=curr1->l;
    curr2=curr2->l;
}
if(curr1)
return curr1->data;
else
return -1;
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

}