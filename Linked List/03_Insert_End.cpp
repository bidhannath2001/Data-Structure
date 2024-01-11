#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};

Node *head = NULL;
void insertEnd(int d){
    Node *endNode = new Node();
    endNode->data = d;
    endNode->link = NULL;
    if(head==NULL){     //empty list
        head = endNode;
    }

    else{
        Node *temp = new Node();
        temp = head;
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = endNode;
    }
}
int main ()
{
    Node *first  = new Node();
    Node *second = new Node();
    Node *third = new Node();
    first->data = 1;
    second->data = 2;
    third->data = 3;

    head = first;
    first->link = second;
    second->link =third;
    third->link = NULL;

    insertEnd(5);
    
    Node *iteration = head;
    while(iteration!=NULL){
        cout<<iteration->data <<" ";
        iteration = iteration->link;
    }
}