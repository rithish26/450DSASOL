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
void findmiddle(node*curr,node**first,node**second)
{
    node*fast=curr->l;
    node*slow=curr;
    while(slow&&fast&&fast->l)
    {
        slow=slow->l;
        fast=fast->l;
    }
    *first=curr;
    *second=slow->l;
    slow->l=NULL;
}
node*mergeboth(node*first,node*second)
{
    node*answer=NULL;
    if(!first)
    {
        return second;
    }
    if(!second)
    {
        return first;
    }
    if(first->data<second->data)
    {
        answer=first;
        answer->l=mergeboth(first->l,second);
    }
    else
    {
        answer=second;
        answer->l=mergeboth(first,second->l);
    }
    return answer;
}
void mergesort(node**head)
{
    node*curr=*head;
    node*first;
    node*second;
    if(!curr||!curr->l)
    {
        return;
    }
    findmiddle(curr,&first,&second);
    mergesort(&first);
    mergesort(&second);
    *head=mergeboth(first,second);
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
mergesort(&head);
display(head);
}