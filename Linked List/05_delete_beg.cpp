#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *link;
};
Node *head = NULL;

void add_node(int d){
    Node *add = new Node();
    add->data=d;
    add->link=NULL;
    if(head==NULL){
        head = add;
    }
    else{
        Node *temp = head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=add;
    }
}
//delete from begining
void delete_beg(){
    if(head==NULL){
        cout<<"List is empty!";
    }
    else{
        head = head->link;
    }
}

//printing
void print(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

int main ()
{
    int n;
    cout<<"Enter the number of node: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Enter the value of the node "<<i+1<<": ";
        cin>>x;
        add_node(x);
    }
    delete_beg();
    print(head);
}