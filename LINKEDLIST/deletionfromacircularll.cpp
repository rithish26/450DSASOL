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
    while(cur->l!=head)
    {
        cout<<cur->data<<" ";
        cur=cur->l;
    }
   cout<<cur->data<<endl;
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
void deletenode(node**head,int k)
{
    if((*head)->data==k&&(*head)->l==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    node*last=*head;
    node*d;
    if((*head)->data==k)
    {
        while(last->l!=*head)
        {
            last=last->l;
        }
        last->l=(*head)->l;
        free(*head);
        *head=last->l;
        return;
    }
    while(last->l!=(*head)&&last->l->data!=k)
    {
        last=last->l;
    }
    if(last->l->data==k)
    {
        d=last->l;
        last->l=d->l;
        free(d);
        return;
    }
else
{
    cout<<"GG"<<endl;
}
return;
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
int k;
cin>>k;
deletenode(&head,k);
display(head);
}