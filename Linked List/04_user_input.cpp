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
    Node *iteration = head;
    while(iteration!=NULL){
        cout<<iteration->data<<" ";
        iteration = iteration->link;
    }
    return 0;
}