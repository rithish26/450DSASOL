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
void loophere(node*head,int pos)
{
    node*curr=head;
    while(curr->l!=NULL)
    {
        curr=curr->l;
    }
    node*p=head;
    while(pos)
    {
        p=p->l;
        pos--;
    }
    curr->l=p;
}
bool detectloop(node*head)
{
    node*slow=head;
    node*fast=head;
    while(slow&&fast&&fast->l)
    {
        slow=slow->l;
        fast=fast->l->l;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
void deleteloop(node*head)
{
    if(head==NULL&&head->l==NULL)
    {
        return;
    }
    node*slow=head;
    node*fast=head;
   slow=slow->l;
   fast=fast->l->l;
   while(fast&&fast->l)
   {
       if(slow==fast)
       {
           break;
       }
       slow=slow->l;
       fast=fast->l->l;
       
   }
   if(slow==fast)
       {
           slow=head;
           if(slow==fast)
           {
               while(fast->l!=slow)
               {
                   fast=fast->l;
               }
           }
           else
           {
               while(slow->l!=fast->l)
               {
                   slow=slow->l;
                   fast=fast->l;
               }
           }
           fast->l=NULL;
       }

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
int pos;
cin>>pos;
loophere(head,pos);

display(head);
}