#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *head = NULL;

void insertEnd(int d){
    Node *endNode = new Node();
    endNode->data =  d;
    endNode->link = NULL;
    if(head == NULL){
        head = endNode;
    }
    else{
        Node *temp = head;
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link =  endNode;
    }
}

void reverse_list(){
    Node *p,*c,*n;
    p = NULL;
    c = head;
    while(c!=NULL){
        n=c->link;
        c->link=p;
        p=c;
        c=n;
    }
    head = p;
}

void print(Node *temp){
    if(temp==NULL){
        cout<<"Empty!";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
    cout<<endl;
}
int main ()
{
    int n,value;
    cout<<"Enter the number of Node: ";
    cin>>n;
    for(int i=0;i<n;++i){
        cout<<"Enter the value for the node "<<i+1<<": ";
        cin>>value;
        insertEnd(value);
    }
    print(head);
    reverse_list();
    print(head);
    return 0;
}