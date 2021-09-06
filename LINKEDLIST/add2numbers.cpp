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
node*twoadd(node*head1,node*head2)
{

reversell(&head1);
reversell(&head2);
node*temp;
int c=0;
int s=0;
node*res=NULL;
node*curr=NULL;
while(head1!=NULL||head2!=NULL)
{
s=c+(head1?head1->data:0)+(head2?head2->data:0);
c=(s>=10)?1:0;
s=s%10;
temp=new node(s);
if(res==NULL)
{
    res=temp;
}
else
{
    curr->l=temp;
}
curr=temp;
if(head1)
{
    head1=head1->l;
}
if(head2)
{
    head2=head2->l;
}
}
if(c>0)
{
    temp=new node(c);
    curr->l=temp;
    curr=temp;
}
return res;
}
int main()
{
int n;
cin>>n;
node*head1=NULL;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    head1=insert(head1,x);
}

int m;
cin>>m;
node*head2=NULL;
for(int i=0;i<m;i++)
{
    int x;
    cin>>x;
    head2=insert(head2,x);
}

node*head=twoadd(head1,head2);
reversell(&head);
display(head);

}