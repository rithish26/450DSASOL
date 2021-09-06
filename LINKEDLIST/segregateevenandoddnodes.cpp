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
void segregate(node**head)
{
    node*end=*head;
    node*prev=NULL;
    node*curr=*head;

    while(end->l!=NULL)
    {
        end=end->l;
    }
    node*newend=end;
    while(curr->data%2!=0&&curr!=end)
    {
        newend->l=curr;
        curr=curr->l;
        newend->l->l=NULL;
        newend=newend->l;
    }
    if(curr->data%2==0)
    {
        *head=curr;
        while(curr!=end)
        {
            if(curr->data%2==0)
            {
                prev=curr;
                curr=curr->l;
            }
            else
            {
                prev->l=curr->l;
                curr->l=NULL;
                newend->l=curr;
                newend=curr;
                curr=prev->l;
            }
        }
    }
    else
    prev=curr;
    if(newend!=end&&(end->data)%2!=0)
    {
        prev->l=end->l;
        end->l=NULL;
       newend->l=end;
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
reversell(&head);
display(head);
}