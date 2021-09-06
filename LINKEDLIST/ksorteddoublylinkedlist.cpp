#include <bits/stdc++.h>
using namespace std;
struct node
{
int data;
node*l;
node*p;
node(int x)
{
    data=x;
    l=NULL;
    p=NULL;
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
    node*temp=new node(x);
    curr->l=temp;
    temp->p=curr;
    return head;
}
void display(node* head)
{
    node*curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->l;
    }

}
void reverse(node**head)
{
    node*curr=*head;
    node*temp=NULL;
 while(curr!=NULL)
 {
     temp=curr->p;
     curr->p=curr->l;
     curr->l=temp;
     curr=curr->p;
 }
 if(temp!=NULL)
 {
     *head=temp->p;
 }
}
struct cmp
{
bool operator()(node*p1,node*p2)
{
    return  p1->data>p2->data;
}
};
node*sort(node*head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    priority_queue<node*,vector<node*>,cmp>pq;
    node*newhead=NULL;
    node*last;
    for(int i=0;head!=NULL&&i<=k;i++)
    {
        pq.push(head);
        head=head->l;
    }
    while(!pq.empty())
    {
        if(newhead==NULL)
        {
            newhead=pq.top();
            newhead->p=NULL;
            last=newhead;
        }
        else
        {
            last->l=pq.top();
            pq.top()->p=last;
            last=pq.top();
        }
        pq.pop();
        if(head!=NULL)
        {
            pq.push(head);
            head=head->l;
        }
        
        
    }
    last->l=NULL;
    return newhead;
}
void rotatebyn(node*&head,int pos)
{
    node*curr=head;
    while(curr->l!=NULL)
    {
        curr=curr->l;
    }
    curr->l=head;
    head->p=curr;
    int count=1;
    while(count<=pos)
    {
        head=head->l;
        curr=curr->l;
        count++;
    }
    head->p=NULL;
    curr->l=NULL;
}
int main()
{
node*head=NULL;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    head=insert(head,x);
}
int k;
cin>>k;
node*he=sort(head,k);
display(he);
}