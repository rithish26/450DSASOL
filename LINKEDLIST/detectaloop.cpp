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
bool detectloop(node*k)
{
    node*curr=k;
    map<node*,int>mp;
    while(curr!=NULL)
    {
        if(mp[curr])
        {
            return true;
        }
        mp[curr]++;
        curr=curr->l;

    }
    return false;
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
int k;
cin>>k;
head=reversepart(head,k);
display(head);
}