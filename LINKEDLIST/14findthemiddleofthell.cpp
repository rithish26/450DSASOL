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
int findmiddle(node*head)
{
    node*fast=head;
    node*slow=head;
    while(fast&&fast->l)
    {
        fast=fast->l->l;
        slow=slow->l;
    }
    return slow->data;
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
cout<<findmiddle(head)<<endl;
}