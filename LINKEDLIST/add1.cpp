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
node*add1(node*head)
{
    node*curr=head;
   bool f=1;
   while(curr!=NULL&&f==true)
   {
       if(curr->data==9&&curr->l==NULL)
       {
          curr->data=1;
          node*temp=new node(0);
          temp->l=head;
          head=temp;
          curr=curr->l;
       }
       else if(curr->data==9)
       {
           curr->data=0;
           curr=curr->l;
       }
       else
       {
           curr->data+=1;
           curr=curr->l;
           f=false;
       }
   }
return head;
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
head=add1(head);
reversell(&head);
display(head);
}