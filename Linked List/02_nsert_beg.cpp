#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};

Node *head = NULL;

void insertBeg(int d){
        Node *begNode = new Node();
        begNode->data = d;
        begNode->link = head;
        head = begNode;
}

int main ()
{
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    first->data = 1;
    second->data = 2;
    third->data = 3;

    head = first;
    first->link = second;
    second->link = third;
    third->link = NULL;

    insertBeg(5);

    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    return 0;
}