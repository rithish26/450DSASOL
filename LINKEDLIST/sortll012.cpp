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
void sortlist(node*head)
{
    int count[3]={0,0,0};
    node*ptr=head;
    while(ptr!=NULL)
    {
        count[ptr->data]+=1;
        ptr=ptr->l;
    }
    int i=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(count[i]==0)
        {
            i++;
        }
        else
        {
            ptr->data=i;
            --count[i];
            ptr=ptr->l;
        }
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
sortlist(head);
display(head);
}