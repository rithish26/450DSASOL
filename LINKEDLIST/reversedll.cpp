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
reverse(&head);
display(head);
}